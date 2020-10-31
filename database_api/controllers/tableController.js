const chpConnection = require('../CHPconection');

// Controller that interacts with tabels to retrieve data.
class TableController {
    constructor() {
        console.log('table Controller Initialized!');
    }

    // Fetches all tables
    async Tables(ctx, next) {
        console.log('Controller HIT: tableController::tables');
        return new Promise((resolve, reject) => {
            const query = 'SELECT * FROM `table`';

            chpConnection.query(query, (err, res) => {
                if (err) {
                    reject(`Error querying CHP.test: ${err}`);
                }

                ctx.body = res;
                ctx.status = 200;

                resolve();
            });
        })
            .then(await next)
            .catch(err => {
                ctx.status = 500;
                ctx.body = err;
            });
    }

    // adds a new table
    async addTable(ctx, next) {
        console.log('Controller HIT: tableController::openTabes')
        return new Promise((resolve, reject) => {
            chpConnection.query({
                    sql: 'INSERT INTO `table`(rest_id, nbr, `status`) VALUE(?, ?, ?)',
                    values: [ctx.params.id, ctx.params.nbr, ctx.params.status]
            }, (err, res) => {
                if (err) {
                    reject(`Error querying CHP.test: ${err}`);
                }

                ctx.body = res;
                ctx.status = 200;

                resolve();
            });
        })
            .then(await next)
            .catch(err => {
                ctx.status = 500;
                ctx.body = err;
            });
    }

    //updates all tables to closed
    async openTables(ctx) {
        console.log('Controller HIT: tableController::openTabes')
        return new Promise((resolve, reject) => {
            chpConnection.query({
                    sql: 'UPDATE `table` SET `status` = "open" WHERE rest_id = ?',
                    values: [ctx.params.id]
            }, (err, res) => {
                if (err) {
                    reject(`Error querying CHP.test: ${err}`);
                }

                ctx.body = res;
                ctx.status = 200;

                resolve();
            });
        })
            .catch(err => {
                ctx.status = 500;
                ctx.body = err;
            });
    }
}

module.exports = TableController;
