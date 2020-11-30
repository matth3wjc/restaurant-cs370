const partyController = new(require('../controllers/partyController.js'))();

const partyRouter = require('koa-router')({
    prefix: '/party'
});

partyRouter.get('/:id', partyController.parties);
partyRouter.get('/:id/:name/:size/add', partyController.addParty);
partyRouter.get('/:id/:name/updatename', partyController.updateName);
partyRouter.get('/:id/:size/updatesize', partyController.updateSize);
partyRouter.get('/:id/:name/:size/updatenameandsize', partyController.updateNameAndSize);
partyRouter.get('/:restid/:partyid/:tablenbr/sitparty', partyController.sitParty);
partyRouter.get('/:id/delete', partyController.deleteParty);

module.exports = partyRouter;