// Created by Nicole Taketa and Luke Shoulders

const partyController = new(require('../controllers/partyController.js'))();

const partyRouter = require('koa-router')({
    prefix: '/party'
});

partyRouter.get('/:id', partyController.parties);// Created by Luke Shoulders
partyRouter.get('/:id/:name/:size/add', partyController.addParty);// Created by Luke Shoulders
partyRouter.get('/:id/:name/updatename', partyController.updateName);// Created by Nicole Taketa
partyRouter.get('/:id/:size/updatesize', partyController.updateSize);// Created by Nicole Taketa
partyRouter.get('/:id/:name/:size/updatenameandsize', partyController.updateNameAndSize);// Created by Nicole Taketa
partyRouter.get('/:restid/:partyid/:tablenbr/sitparty', partyController.sitParty);// Created by Nicole Taketa
partyRouter.get('/:id/delete', partyController.deleteParty);// Created by Nicole Taketa

module.exports = partyRouter;