function isEmpty(obj: Record<string, any> | any[]): boolean {
    return ((obj instanceof Array) && obj.length === 0) || Object.keys(obj).length === 0
};