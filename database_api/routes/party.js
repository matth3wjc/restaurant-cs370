const partyController = new(require('../controllers/partyController.js'))();

const partyRouter = require('koa-router')({
    prefix: '/party'
});

partyRouter.get('/:id', partyController.parties);
partyRouter.get('/:id/:name/:size', partyController.addParty);
module.exports = partyRouter;
