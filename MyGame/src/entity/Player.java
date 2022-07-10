package entity;

import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.LinkedList;

import javax.imageio.ImageIO;

import main.GamePanel;
import main.KeyHandler;

public class Player extends Entity {
	GamePanel gp;
	KeyHandler keyH;
	String oldPos = "right";
	private float gravity;
	
	
	public  int screenX;
	public  int screenY;
	
	public Player(GamePanel gp,KeyHandler keyH) {
		this.gp=gp;
		this.keyH=keyH;
		
		screenX = gp.screenWidth/2 - (gp.tileSize/2);
		screenY = gp.screenHeight/2 - (gp.tileSize/2);
		
		solidArea = new Rectangle(8,16,32,32);
		
				
		setDefaultValues();
		getPlayerImage();
	}
	
	public void setDefaultValues() {
		worldX = gp.tileSize*7;//Pour toujours avoir la vision à cet endroit (ou apparaitre à cet endroit)
		worldY = gp.tileSize*5;
		speed = 4;
		direction = "left";
		jumpStrengthY = gp.tileSize*6;
		jumpStrengthX = gp.tileSize*2;
	}
	
	public void getPlayerImage() {
		try {
			
			upRight = ImageIO.read(getClass().getResourceAsStream("/player/boy_upRight.png"));
			upLeft = ImageIO.read(getClass().getResourceAsStream("/player/boy_upLeft.png"));
			left1 = ImageIO.read(getClass().getResourceAsStream("/player/boy_left_1.png"));
			left2 = ImageIO.read(getClass().getResourceAsStream("/player/boy_left_2.png"));
			right1 = ImageIO.read(getClass().getResourceAsStream("/player/boy_right_1.png"));
			right2 = ImageIO.read(getClass().getResourceAsStream("/player/boy_right_2.png"));
			
			
			
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	public void update() {
		if(keyH.spacePressed ||keyH.leftPressed == true ||keyH.rightPressed == true) {
			if(keyH.spacePressed == true) {
				direction ="up";
				// valeur de X augmentent à droite, valeur de Y augmentent vers le bas
			}
			else if (keyH.leftPressed == true) {
				oldPos = direction;
				direction ="left";
				
			}
			else if (keyH.rightPressed == true) {
				oldPos = direction;
				direction  = "right";
			
			}
			
			
			
			//CHECK TILE COLLISION
			collisionOn = false;
			gp.cChecker.checkTile(this);
			
			
			
			
			
			//IF COLLISSION IS FALSE,PLAYER CAN MOVE
			if (collisionOn == false) {
				switch(direction) {
				case "left":
					worldX -= speed;
					break;
				case "right":
					worldX += speed;
					break;
				case "up":
					if (collisionGrav == false) {
						jumping = true;
						gravity();
						if (oldPos == "right") {
							worldX += jumpStrengthX;
						}
						else if (oldPos == "left"){
							worldX -= jumpStrengthX;
						}
						//jumpStrenth -= weight;
						jumping = false;
					}
					
					
					break;
				}
			}
			
			spriteCounter++;
			if(spriteCounter > 12) {
				if (spriteNum ==1) {
					spriteNum = 2;
				}
				else if (spriteNum ==2){
					spriteNum = 1;
				}
				spriteCounter = 0;
			}
		}
		
	}
	public void draw(Graphics2D g2) {
		
		BufferedImage image = null;
		
		switch(direction) {

		case "left":
			if (spriteNum==1) {
				image = left1;
			}
			if(spriteNum==2) {
				image = left2;
			}
			break;
		
		case "right":
			if (spriteNum==1) {
				image = right1;
			}
			if(spriteNum==2) {
				image = right2;
			}
			break;
		case "up":
			if (oldPos == "right") {
				image = upRight;
			}
			if(oldPos == "left") {
				image = upLeft;
			}
			break;
		}
		g2.drawImage(image, screenX, screenY, gp.tileSize, gp.tileSize, null);
	}
	
	public void gravity() {
		gp.cChecker.checkBottomTile(this);
		gravity = (float) (gp.tileSize / 9 );
		
		if (collisionGrav == true && jumping == false) {
			worldY += gravity;
		}else if (jumping == true) {
			worldY -= gp.tileSize*9;
		}
	}
	
	
	
	
}
