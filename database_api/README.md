How to spin up the database api server
====================================

what you need
-------------

- [Node.js](https://nodejs.org/en/download/)
- [MySQL Workbench](https://dev.mysql.com/downloads/workbench/) with default installation
- completion of database_sql_files/README.md

steps
-----

- open a terrminal and cd into this foulder
- enter 'npm install' this should download all the needed modules
- wait for modules to download
- enter 'node index.js'
- the terminal should print:

  ![Image](example.png)
  
 - don't exit the terminal
 - to make sure everything works search [http://localhost:3000/api/table/]("http://localhost:3000/api/table/") in your web browser
 - you should see a list of all the tables in the database
 - to turn the server off enter ctrl c into the ternimal
 - to start the server back up enter 'node index.js' again
