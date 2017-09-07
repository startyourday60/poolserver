CREATE TABLE IF NOT EXISTS `pool_worker` 
(
	`id` INT NOT NULL,
	`mindiff` INT,
	`username` VARCHAR(64),
	`password` VARCHAR(64),
	PRIMARY KEY (`id`)
)
ENGINE = InnoDB;

