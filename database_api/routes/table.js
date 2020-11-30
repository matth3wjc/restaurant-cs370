const TableController = require('../controllers/tableController.js');

const tableController = new(require('../controllers/tableController.js'))();

const tableRouter = require('koa-router')({
    prefix: '/table'
});


tableRouter.get('/', tableController.Tables);
tableRouter.get('/:id/:nbr/:status', tableController.addTable, tableController.Tables);
tableRouter.get('/:id', tableController.openTables);
tableRouter.get('/:id/:nbr/:status/updatestatus', tableController.updateTableStatus);



module.exports = tableRouter;