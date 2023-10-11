const PuppeteerEnvironment = require('jest-environment-puppeteer');
const setup = require('jest-environment-puppeteer/setup');
const teardown = require('jest-environment-puppeteer/teardown');

class BrowserEnvironment extends PuppeteerEnvironment {
  constructor(config, context) {
    super(config, context);
  }

  async setup() {
    await setup();
    await super.setup();
  }

  async teardown() {
    await super.teardown();
    await teardown();
  }
}

module.exports = BrowserEnvironment;
