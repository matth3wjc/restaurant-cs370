const chpConection = require('../CHPconection');

class partyController{
    constructor(){
        console.log('party Controller Initialized!');
    }

    async parties(ctx, next){
        console.log('Controller HIT: partyController::parties')
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql:    `select p_name, p_size
                        from wait_list AS w
                        JOIN party AS p
                            ON p.p_id = w.p_id
                        JOIN resturant AS r
                            ON w.rest_id = r.rest_id
                        WHERE r.rest_id = ?;`,
                values: [ctx.params.id]
            }, (err, res) => {
                if (err){
                    reject(`Error querying CHP.test: ${err}`);
                }

                ctx.body = res;
                ctx.status = 200;
                
                resolve();
            });
        })
        .then(await next)
        .catch(err =>{
            ctx.body = err;
            ctx.status = 500;
        });
    }


    async addParty(ctx, next) {
        console.log("Controller HIT: partyController::addParty");
        return new Promise((reject, resolve) => {
            chpConection.query({
                sql: 'CALL proc_add_party( ?, ?, ? );',
                values: [ctx.params.id, ctx.params.name, ctx.params.size]
            }, (err, res) => {
                if (err){
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
}

module.exports = partyController;