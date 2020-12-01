// Created by Luke Shoulders

const tableRouter = require('./table');
const partyRouter = require('./party');
const defaultRouter = require('koa-router')({
    prefix: '/api'
});

defaultRouter.get('/', ctx => {
    ctx.status = 200;
    ctx.body = "Default Route Found!";
});

defaultRouter.use(
    tableRouter.routes(),
    partyRouter.routes()
);

module.exports = api => {
    api.use(defaultRouter.routes());
};