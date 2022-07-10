package main;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

import entity.Player;
import tile.TileManager;

public class GamePanel extends JPanel implements Runnable{
	final int orginalTitleSize = 16; //16x16 tuile
	final int scale = 3;
	
	public final int tileSize = orginalTitleSize * scale; //48x48 tuile
	public final int maxScreenCol = 16;
	public final int maxScreenRow = 12;
	public final int screenWidth = tileSize*maxScreenCol; //768 pixels
	public final int screenHeight = tileSize*maxScreenRow; //576 pixels
	
	//WORLD SETTINGS
	public final int maxWorldCol = 50;
	public final int maxWorldRow = 50;
	public final int worldWidth = tileSize * maxWorldCol;
	public final int wordlHeight = tileSize * maxWorldRow;
	
	int FPS = 60;
	
	
	KeyHandler keyH = new KeyHandler();
	TileManager tileM = new TileManager(this);
	Thread gameThread;
	public CollisionChecker cChecker = new CollisionChecker(this);
	
	public Player player = new Player(this,keyH);
	
	
	
	
	
	public GamePanel() {
		this.setPreferredSize(new Dimension(screenWidth,screenHeight));//Set the size of thise class (JPanel)
		this.setBackground(Color.black);
		this.setDoubleBuffered(true);// all the drawing from this component will be done in an offscreen painting buffer
		this.addKeyListener(keyH);
		
		this.setFocusable(true);//Avec �a le gamePanel peut �tre "focus" � recevoir des entr�es utilisateurs
		
		// -> Permet d'am�liorer les performance de rendu du jeux
	}
	public void startGameThread() {
		gameThread = new Thread(this);
		gameThread.start();
	}
	
	@Override
	public void run() {
		double drawInterval = 1000000000/FPS; //0.01666 seconds
		double nextDrawTime = System.nanoTime() + drawInterval;
		
		
		while(gameThread != null) {
			
			//Check gravity
			player.gravity();
			
			//1 UPDATE : update information such as character positions
			update();
			
			
			
			//2 DRAW : draw the screen with the updated information
			repaint();//Appel paintComponent
			
			
			try {
				double remainingTime = nextDrawTime-System.nanoTime();
				remainingTime = remainingTime/1000000;
				
				if(remainingTime < 0) {
					remainingTime=0;
				}
				
				Thread.sleep((long) remainingTime);
				
				nextDrawTime += drawInterval;
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	
	public void update() {
		player.update();
	}
	
	public void paintComponent(Graphics g) {//Graphics import beaucoup de fonction pour dessiner un objet sur l'�cran
		super.paintComponent(g);
		
		Graphics2D g2 = (Graphics2D)g;//Graphics2D donne des contr�les plus sophistiqu�s avec de la geom�trie,des coordonn�es...
		
		//TILE
		tileM.draw(g2);
		
		
		
		//PLAYER
		player.draw(g2);
		
		g2.dispose();//Supprime ce contexte graphique et lib�re toutes les ressources syst�me qu'il utilise.
	}
}
