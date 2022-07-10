package main;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import entity.Player;


public class KeyHandler implements KeyListener{
	public boolean leftPressed,rightPressed,spacePressed;
	
	
	public void keyTyped(KeyEvent e) {
			
	}
	
	
	public void keyPressed(KeyEvent e) {
		int code=e.getKeyCode(); //Renvoie l'entier keyCode associé à la clé dans cet événement. exemple : 8=espace,10=entrer,66=B...
		if (code==KeyEvent.VK_Q) {
			leftPressed = true;
		}
		if (code==KeyEvent.VK_D) {
			rightPressed = true;
		}
		if (code == KeyEvent.VK_SPACE) {
			spacePressed = true;
			
		}
	};
	
	

	@Override
	public void keyReleased(KeyEvent e) {
		int code = e.getKeyCode();
		
		if (code==KeyEvent.VK_Q) {
			leftPressed = false;
		}
		if (code==KeyEvent.VK_D) {
			rightPressed = false;
		}
		if (code == KeyEvent.VK_SPACE) {
			spacePressed = false;
		}
		
		
	};
	
	
	
	
	
}
