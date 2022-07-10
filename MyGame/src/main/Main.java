package main;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame window = new JFrame();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//Ferme proprement la fenêtre qu'on on appuie sur la croix
		window.setResizable(false);
		window.setTitle("2D Adventure");
		
		GamePanel gamePanel = new GamePanel();
		window.add(gamePanel);
		
		window.pack();//Permet à la fenêtre d'être dimensionné pour s'adapter à la taille et aux disposition préféré de 
		// ses sous composents (=gamePanel)
		
		window.setLocationRelativeTo(null);//La fenêtre s'affichera au centre de l'écran
		window.setVisible(true);
		
		//gamePanel.setupGame();
		gamePanel.startGameThread();
	}
}
