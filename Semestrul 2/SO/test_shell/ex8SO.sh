#!/bin/bash


awk "{print}" "ds.fake" | awk '{print $2, $4}'
