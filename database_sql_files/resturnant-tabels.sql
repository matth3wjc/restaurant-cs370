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
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);


CREATE TABLE wait_list
(
	p_id BIGINT,
    rest_id BIGINT,
    PRIMARY KEY(p_id, rest_id),
    FOREIGN KEY (rest_id) 
		REFERENCES resturant(rest_id)
        ON DELETE CASCADE,
	FOREIGN KEY (p_id)
		REFERENCES party(p_id)
        ON DELETE CASCADE
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


-- insert into party (p_name, p_size) values ("Jones", 4), ("mary sue", 3), ("Carl Smithers", 1);
-- insert into wait_list values (1, 1), (2, 1);
-- insert into `table` (nbr, `status`, rest_id) values (1, "closed", 2), (1, "open", 1);
-- insert into `table` values (2, "seated", 1, 1);
/*
select * 
	from `table` AS t
    JOIN resturant AS r
		ON t.rest_id = r.rest_id
	WHERE rest_name = "Jenny's Patio";
    
select p_name, p_size
	from wait_list AS w
    JOIN party AS p
		ON p.p_id = w.p_id
    JOIN resturant AS r
		ON w.rest_id = r.rest_id
	WHERE rest_name = "Jenny's Patio";
    
select * from party;
*/
/*
select func_add_party(1, "tim", 3);

select *  from party;
select nbr, `status`, p_name 
from `table` t 
LEFT JOIN party p ON p.p_id = t.p_id
where rest_id = 1;

SELECT nbr, `status`, rest_id FROM `table` WHERE rest_id = 1;
*/