module Model = SiikaModel;

module Query = SiikaQuery;

module Record = SiikaRecord;

include SiikaApp;

let sequelize = SiikaApp.create;