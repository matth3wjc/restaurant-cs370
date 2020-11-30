DROP FUNCTION IF EXISTS func_add_party;
DELIMITER $$
CREATE FUNCTION func_add_party
(
	 _rest_id BIGINT,
    _p_name VARCHAR(30),
    _p_size int
)
RETURNS BIGINT
BEGIN

	DECLARE _p_id BIGINT;

	INSERT INTO party( p_name, p_size) VALUE (_p_name, _p_size);
    INSERT INTO wait_list VALUE ( last_insert_id(), _rest_id);
    SELECT p_id INTO _p_id
		FROM wait_list
        WHERE p_id = last_insert_id() AND rest_id = _rest_id;
    RETURN _p_id;
END $$
DELIMITER ;


DROP PROCEDURE IF EXISTS proc_make_party;
DELIMITER $$
CREATE PROCEDURE proc_make_party
(
	 _number_of_tables INT
)
BEGIN
	add_table: LOOP
		IF _number_of_tables > 0 THEN
			INSERT INTO `table`(nbr, `status`, rest_id) VALUES (_number_of_tables, "DNE", 1);
			SET _number_of_tables = _number_of_tables - 1;
			ITERATE add_table;
		END IF;
		LEAVE add_table;
    END LOOP add_table;
END $$
DELIMITER ;



DROP PROCEDURE IF EXISTS proc_update_table_status;
DELIMITER $$
CREATE PROCEDURE proc_update_table_status
(
	 _rest_id BIGINT,
     _nbr INT,
     _new_status VARCHAR(15)
)
BEGIN
	UPDATE `table` SET `status` = _new_status WHERE nbr = _nbr AND rest_id = _rest_id;
END $$
DELIMITER ;

DROP PROCEDURE IF EXISTS proc_update_name;
DELIMITER $$
CREATE PROCEDURE proc_update_name
(
_id BIGINT,
_new_name VARCHAR(30)
)
BEGIN
	UPDATE party SET p_name = _new_name WHERE p_id = _id;
END $$
DELIMITER ;


DROP PROCEDURE IF EXISTS proc_update_size;
DELIMITER $$
CREATE PROCEDURE proc_update_size
(
_id BIGINT,
_new_size INT
)
BEGIN
	UPDATE party SET p_size = _new_size WHERE p_id = _id;
END $$
DELIMITER ;


DROP PROCEDURE IF EXISTS proc_update_name_and_size;
DELIMITER $$
CREATE PROCEDURE proc_update_name_and_size
(
_id BIGINT,
_new_name VARCHAR(30),
_new_size INT
)
BEGIN
	UPDATE party SET p_name = _new_name WHERE p_id = _id;
	UPDATE party SET p_size = _new_size WHERE p_id = _id;
END $$
DELIMITER ;


DROP PROCEDURE IF EXISTS proc_delete_party;
DELIMITER $$
CREATE PROCEDURE proc_delete_party
(
_id BIGINT
)
BEGIN
	DELETE FROM party WHERE p_id = _id;
END $$
DELIMITER ;


DROP PROCEDURE IF EXISTS proc_sit_party;
DELIMITER $$
CREATE PROCEDURE proc_sit_party
(
_rest_id BIGINT,
_id BIGINT,
_table_nbr INT
)
BEGIN
	UPDATE party SET `status` = "SEATED" WHERE p_id = _id;
    DELETE FROM `table` WHERE nbr = _table_nbr AND rest_id = _rest_id;
    INSERT INTO `table`(nbr, `status`, rest_id, p_id) VALUES (_table_nbr, "SEATED", 1, _id);
END $$
DELIMITER ;
