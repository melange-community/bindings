#!/usr/bin/env sh

NPM_VERSION=$(jq ".version" package.json)
BS_VERSION=$(jq ".version" bsconfig.json)

if [ "$NPM_VERSION" != "$BS_VERSION" ]; then
  echo "Versions do not match. Exiting..."
  exit 1
fi
