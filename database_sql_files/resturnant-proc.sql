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
			INSERT INTO `table`(nbr, `status`, rest_id) VALUES (_number_of_tables, "CLOSED", 1);
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