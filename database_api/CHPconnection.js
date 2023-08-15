// Created by Luke Shoulders

const mySQL = require('mysql');
const chpConnection = mySQL.createConnection({
        debug: false,
        host: 'localhost',
        user: 'root',
        password: 'password',
        database: 'restaurant'
});

module.exports = chpConnection;
