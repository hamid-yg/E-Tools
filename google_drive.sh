#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m'

echo -e "${GREEN}Mounting Google-drive account${NC}"

google-drive-ocamlfuse -label hamid ~/GoogleDrive/hamidtessilimi@gmail.com
google-drive-ocamlfuse -label bde ~/GoogleDrive/bde.epitechcotonou@gmail.com