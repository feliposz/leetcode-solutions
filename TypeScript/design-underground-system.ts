class UndergroundSystem {
    users: Users
    travel: TravelLogs

    constructor() {
        this.users = {}
        this.travel = {}
    }

    checkIn(id: number, stationName: string, t: number): void {
        this.users[id] = { stationName, t }
    }

    checkOut(id: number, stationName: string, t: number): void {
        const startTime: number = this.users[id].t
        const endTime: number = t
        const delta: number = endTime - startTime
        const startStation: string = this.users[id].stationName
        const endStation: string = stationName
        if (!(startStation in this.travel)) {
            this.travel[startStation] = {}
        }
        if (!(stationName in this.travel[startStation])) {
            this.travel[startStation][stationName] = { count: 0, totalTime: 0 }
        }
        this.travel[startStation][stationName].count++
        this.travel[startStation][stationName].totalTime += delta
    }

    getAverageTime(startStation: string, endStation: string): number {
        const travel: TravelLog = this.travel[startStation][endStation]
        return travel.totalTime / travel.count
    }
}

type UserChekin = { stationName: string, t: number }
type Users = { [field: string]: UserChekin }
type TravelLog = { count: number, totalTime: number }
type TravelLogs = { [startStation: string]: { [endStation: string]: TravelLog } };

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * var obj = new UndergroundSystem()
 * obj.checkIn(id,stationName,t)
 * obj.checkOut(id,stationName,t)
 * var param_3 = obj.getAverageTime(startStation,endStation)
 */
