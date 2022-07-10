package main;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame window = new JFrame();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//Ferme proprement la fen�tre qu'on on appuie sur la croix
		window.setResizable(false);
		window.setTitle("2D Adventure");
		
		GamePanel gamePanel = new GamePanel();
		window.add(gamePanel);
		
		window.pack();//Permet � la fen�tre d'�tre dimensionn� pour s'adapter � la taille et aux disposition pr�f�r� de 
		// ses sous composents (=gamePanel)
		
		window.setLocationRelativeTo(null);//La fen�tre s'affichera au centre de l'�cran
		window.setVisible(true);
		
		//gamePanel.setupGame();
		gamePanel.startGameThread();
	}
}
