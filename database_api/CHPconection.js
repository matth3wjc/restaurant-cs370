// Created by Luke Shoulders

const mySQL = require('mysql');
const chpConnection = mySQL.createConnection({
        debug: false,
        host: 'localhost',
        user: 'root',
        password: 'password',
        database: 'resturant'
});

module.exports = chpConnection;
