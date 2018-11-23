DROP TABLE IF EXISTS `pool_worker`;
CREATE TABLE IF NOT EXISTS `pool_worker`
(
  `id` INT(255) NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(50) DEFAULT NULL,
  `password` VARCHAR(50) DEFAULT NULL,
  `mindiff` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
)
ENGINE = InnoDB;

DROP TABLE IF EXISTS `shares`;
CREATE TABLE `shares` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `rem_host` varchar(255) NOT NULL,
  `username` varchar(120) NOT NULL,
  `our_result` tinyint(1) NOT NULL DEFAULT '0',
  `upstream_result` tinyint(1) NOT NULL DEFAULT '0',
  `reason` varchar(50) DEFAULT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `difficulty` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB;

