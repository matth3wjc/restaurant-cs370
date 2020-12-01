-- Created by Luke Shoulders

USE resturant;
DROP TABLE IF EXISTS `table`;
DROP TABLE IF EXISTS wait_list;
DROP TABLE IF EXISTS party;
DROP TABLE IF EXISTS resturant;
SET GLOBAL log_bin_trust_function_creators = 1;

CREATE TABLE resturant
(
	rest_name VARCHAR(30),
    rest_id BIGINT PRIMARY KEY AUTO_INCREMENT
);


CREATE TABLE party
(
	p_id BIGINT PRIMARY KEY AUTO_INCREMENT,
    p_name VARCHAR(30),
    p_size INT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    rest_id BIGINT,
    `status` VARCHAR(15) DEFAULT "WAITING",
    FOREIGN KEY (rest_id) 
		REFERENCES resturant(rest_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);


CREATE TABLE `table`
(
	nbr INT,
    `status` VARCHAR(15),
    rest_id BIGINT,
    p_id BIGINT,
    PRIMARY KEY(nbr, rest_id),
    FOREIGN KEY (rest_id) 
		REFERENCES resturant(rest_id)
        ON DELETE CASCADE,
	FOREIGN KEY (p_id)
		REFERENCES party(p_id)
        ON DELETE CASCADE
);
