const mySQL = require('mysql');
const chpConnection = mySQL.createConnection({
        debug: false,
        host: 'localhost',
        user: 'root',
        password: 'CircleTopEatNo84',
        database: 'resturant'
});

module.exports = chpConnection;
