#!/bin/bash

folder = pwd | awk -F'/' '{print $5}'

git add .
git commit -m "update $folder"
git push origin
git push otahiri master
