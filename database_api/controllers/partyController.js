const chpConection = require('../CHPconection');

class partyController{
    constructor(){
        console.log('party Controller Initialized!');
    }

    async parties(ctx, next){
        console.log('Controller HIT: partyController::parties')
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql:    'select p_id, p_name, p_size  from party where `status` = "WAITING";',
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
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql: 'SELECT func_add_party( ?, ?, ? ) AS new_id;',
                values: [ctx.params.id, ctx.params.name, ctx.params.size]
            }, (err, res) => {
                if (err){
                    reject(`Error querying CHP.test: ${err}`);
                }

                ctx.body = res[0].new_id;
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
