// Created by Nicole Taketa and Luke Shoulders

const chpConection = require('../CHPconection');

class partyController{
    constructor(){
        console.log('party Controller Initialized!');
    }

    async parties(ctx, next){// Created by Luke Shoulders
        console.log('Controller HIT: partyController::parties')
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql:    'select p_id, p_name, p_size from party where `status` = "WAITING";',
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


    async addParty(ctx, next) {// Created by Luke Shoulders
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

    async deleteParty(ctx, next) {// Created by Nicole Taketa
        console.log("Controller HIT: partyController::deleteParty");
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql: 'call proc_delete_party( ?);',
                values: [ctx.params.id]
            }, (err, res) => {
                if(err){
                    reject('Error querying CHP.test: ${err}');
                }

                ctx.status = 204;

                resolve();
            });
        })
        .catch(err => {
            ctx.status = 500;
            ctx.body = err;
        });
    }


    async updateName(ctx, next) {// Created by Nicole Taketa
        console.log("Controller HIT: partyController::updateName");
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql: 'call proc_update_name( ?, ?);',
                values:[ctx.params.id, ctx.params.name]
            }, (err, res) => {
                if(err){
                    reject('Error querying CHP.test: ${err}');
                }
                ctx.status = 204;

                resolve();
            });
        })
        .catch(err => {
            ctx.status = 500;
            ctx.body = err;
        });
    }

    async updateSize(ctx, next) {// Created by Nicole Taketa
        console.log("Controller HIT: partyController::updateSize");
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql: 'call proc_update_size( ?, ?);',
                values: [ctx.params.id, ctx.params.size]
            }, (err, res) => {
                if (err) {
                    reject('Error querying CHP.test ${err}');
                }
                ctx.status = 204;
                resolve();
            });
        })
        .then(await next)
        .catch(err => {
            ctx.status = 500;
            ctx.body = err;
        });
    }

    async updateNameAndSize(ctx, next) {// Created by Nicole Taketa
        console.log("Controller HIT: partyController::updateNameAndSize");
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql: 'call proc_update_name_and_size( ?, ?, ?);',
                values: [ctx.params.id, ctx.params.name, ctx.params.size]
            }, (err, res) => {
                if(err){
                    reject('Error querying CHP.test: ${err}');
                }
                ctx.status = 204;
                resolve();
            });
        })
        .then(await next)
        .catch(err => {
            ctx.status = 500;
            ctx.body = err;
        });
    }

    async sitParty(ctx, next) {// Created by Nicole Taketa
        console.log("Controller HIT: partyController::sitParty");
        return new Promise((resolve, reject) => {
            chpConection.query({
                sql: 'call proc_sit_party( ?, ?, ?);',
                values: [ctx.params.restid, ctx.params.partyid, ctx.params.tablenbr]
            }, (err, res) => {
                if(err){
                    reject('Error querying CHP.test: ${err}');
                }
                ctx.status = 204;

                resolve();
            });
        })
        .catch(err => {
            ctx.status = 500;
            ctx.body = err;
        });
    }
}

module.exports = partyController;
