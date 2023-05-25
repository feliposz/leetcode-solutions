function jsonStringify(object: any): string {
    switch (typeof object) {
        case "number":
        case "boolean":
        case "undefined":
            return object.toString()
        case "string":
            return '"' + object.replace(/"/g, '\\"') + '"'
    }
    if (object instanceof Array) {
        return "[" + object.map(jsonStringify).join(",") + "]"
    }
    if (object === null) {
        return "null"
    }
    return "{" + Object.keys(object).map(key => 
        '"' + key + '":' + jsonStringify(object[key])
    ).join(",") + "}"
};