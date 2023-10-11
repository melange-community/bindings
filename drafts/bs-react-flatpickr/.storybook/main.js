const path = require('path');

module.exports = {
  stories: ['../__stories__/**/*.[tj]s'],
  addons: [
    '@storybook/addon-links',
    '@storybook/addon-actions/register',
    '@storybook/addon-knobs/register',
    '@storybook/addon-notes/register-panel',
  ],
};
