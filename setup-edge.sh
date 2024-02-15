

# Get edge access token
node ./node_modules/@mimik/mimik-edge-cli/bin/run account get-edge-access-token -f ./.devidtoken | jq -r .access_token > .edgetoken

# | jq -R '. as $line | try fromjson catch $line' 
# Associate 

node ./node_modules/@mimik/mimik-edge-cli/bin/run account associate -f ./.edgetoken
