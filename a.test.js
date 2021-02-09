
describe("test", () => {
  it("test", async () => {
    var Libpq = require('libpq');
    var pq = new Libpq();
//    pq.connectSync("host=172.17.0.3 port=5432 dbname=postgres connect_timeout=4 user=postgres password=mysecretpassword");
    pq.connectSync("host=db-postgresql-sfo2-nextgen-do-user-1067699-0.db.ondigitalocean.com port=25060 dbname=treetracker_dev connect_timeout=4 user=doadmin password=l5al4hwte8qmj6x8 sslmode=require");
    const r = pq.exec("select * from xxx");
    console.log("r:", r);
    await new Promise((res, rej) => {
      setTimeout(() => {
        res(true);
      }, 1000);
    });
    console.log("status:", pq.resultStatus());
    console.log("status:", pq.resultErrorMessage());
    console.log("detail:", pq.resultErrorFields());
    pq.finish();
  });
});
