How to spin up the database in MySQL workbench:
    Note(windows only): check the windows 'services' application to make sure your MySQL server is running
    -Open my sql workbech 
    -hit the + next to MySQL Connections
    -in the box connection name enter restaurant
    -press ok to make the conection
    -Open the conecection
    -Open the files in database_sql_files in the connection
    -next run the three files, by pressing the lightning bolt, in this order:
        1.restaurant-tables.sql
        2.restaurant-proc.sql
        3.restaurant-populate.sql
    -now the restaurant database server is running on your computer!