package entity;

import java.awt.Rectangle;
import java.awt.image.BufferedImage;

public class Entity {
	public int worldX,worldY;
	public int speed;
	
	public BufferedImage left1,left2,right1,right2,upRight,upLeft;
	public String direction;
	
	public boolean jumping = false;
	public boolean falling = true;
	public int jumpStrengthY;
	public int jumpStrengthX;
	
	public int weight = 1;
	
	
	public int spriteCounter = 0;
	public int spriteNum = 1;
	
	public Rectangle solidArea;
	public boolean collisionOn = false;
	public boolean collisionGrav = false;
	
	
}
