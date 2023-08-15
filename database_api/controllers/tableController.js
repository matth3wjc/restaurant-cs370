// Created by Nicole Taketa and Luke Shoulders

const chpConnection = require('../CHPconnection');

// Controller that interacts with tabels to retrieve data.
class TableController {
    constructor() {
        console.log('table Controller Initialized!');
    }

    // Fetches all tables
    async Tables(ctx, next) {// Created by Luke Shoulders
        console.log('Controller HIT: tableController::tables');
        return new Promise((resolve, reject) => {
            const query = `select nbr, t.\`status\`, p_name, p.p_id, p_size
                            from \`table\` t 
                            LEFT JOIN party p ON p.p_id = t.p_id
                            where t.rest_id = 1
                            ORDER BY nbr;`;

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
    async addTable(ctx, next) {// Created by Luke Shoulders
        console.log('Controller HIT: tableController::addTable')
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

    //updates all tables to open
    async openTables(ctx) {
        console.log('Controller HIT: tableController::openTabes')
        return new Promise((resolve, reject) => {
            chpConnection.query({
                    sql: 'UPDATE `table` SET `status` = "OPEN" WHERE rest_id = ?',
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

    async updateTableStatus(ctx, next){// Created by Nicole Taketa
        console.log('ControllerHIT: tableController::updateTableStatus')
        return new Promise((resolve, reject) => {
                chpConnection.query({
                        sql: 'call proc_update_table_status( ?, ?, ?);',
                        values: [ctx.params.id, ctx.params.nbr, ctx.params.status]
                }, (err, res) => {
                        if(err) {
                                reject('Error querying CHP.test: ${err}');
                        }
                        ctx.body = res;
                        ctx.status = 200;
                        resolve();
                });
        })
        .then(await next)
        .catch (err => {
                ctx.status = 500;
                ctx.body = err;
        });
    }
}

module.exports = TableController;
