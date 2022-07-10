package main;

import entity.Entity;
import entity.Player;

public class CollisionChecker {
	
	GamePanel gp;
	
	public CollisionChecker(GamePanel gp) {
		this.gp = gp;
	}
	
	public void checkTile(Entity entity) {
		int entityLeftWorldX = entity.worldX + entity.solidArea.x;
		int entityRightWorldX = entity.worldX + entity.solidArea.x + entity.solidArea.width;
		int entityTopWorldY = entity.worldY+entity.solidArea.y;
		int entityBottomWorldY = entity.worldY + entity.solidArea.y + entity.solidArea.height;
		
		int entityLeftCol = entityLeftWorldX/gp.tileSize;
		int entityRightCol = entityRightWorldX/gp.tileSize;
		int entityTopRow = entityTopWorldY/gp.tileSize;
		int entityBottomRow = entityBottomWorldY/gp.tileSize;
		
		int tileNum1,tileNum2,tileNum3,tileNum4,tileNum5,tileNum6;
		
		
		switch(entity.direction) {
			
		case "left":
			entityLeftCol = (entityLeftWorldX - entity.speed)/gp.tileSize;
			tileNum1 = gp.tileM.mapTileNum[entityLeftCol][entityTopRow];
			tileNum2 = gp.tileM.mapTileNum[entityLeftCol][entityBottomRow];
		
			if(gp.tileM.tile[tileNum1].collision == true || gp.tileM.tile[tileNum2].collision == true) {
				entity.collisionOn = true;
			}
			break;
			
		case "right":
			entityRightCol = (entityRightWorldX + entity.speed)/gp.tileSize;
			tileNum1 = gp.tileM.mapTileNum[entityRightCol][entityTopRow];
			tileNum2 = gp.tileM.mapTileNum[entityRightCol][entityBottomRow];
			
			if((gp.tileM.tile[tileNum1].collision == true || gp.tileM.tile[tileNum2].collision == true)) {
				entity.collisionOn = true;
			}
			break;
		}
	}
	public void checkBottomTile(Entity entity) {
		int entityLeftWorldX = entity.worldX + entity.solidArea.x;
		int entityRightWorldX = entity.worldX + entity.solidArea.x + entity.solidArea.width;
		int entityBottomWorldY = entity.worldY + entity.solidArea.y + entity.solidArea.height;
		
		int entityLeftCol = entityLeftWorldX/gp.tileSize;
		int entityRightCol = entityRightWorldX/gp.tileSize;
		
		int entityBottomRow = entityBottomWorldY/gp.tileSize;
		
		int tileNum3,tileNum4;
		entityBottomRow = (entityBottomWorldY + entity.speed)/gp.tileSize;
		tileNum3 = gp.tileM.mapTileNum[entityLeftCol][entityBottomRow];
		tileNum4 = gp.tileM.mapTileNum[entityRightCol][entityBottomRow];
		
		if((gp.tileM.tile[tileNum3].collision == false || gp.tileM.tile[tileNum4].collision == false)) {
			entity.collisionGrav = true;
		}else {
			entity.collisionGrav = false;
		}
	}

	
}
