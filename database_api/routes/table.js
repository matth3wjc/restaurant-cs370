// Created by Nicole Taketa and Luke Shoulders

const TableController = require('../controllers/tableController.js');

const tableController = new(require('../controllers/tableController.js'))();

const tableRouter = require('koa-router')({
    prefix: '/table'
});


tableRouter.get('/', tableController.Tables);// Created by Luke Shoulders
tableRouter.get('/:id/:nbr/:status', tableController.addTable, tableController.Tables);// Created by Luke Shoulders
tableRouter.get('/:id/open', tableController.openTables);// Created by Luke Shoulders
tableRouter.get('/:id/:nbr/:status/updatestatus', tableController.updateTableStatus);// Created by Nicole Taketa



module.exports = tableRouter;
