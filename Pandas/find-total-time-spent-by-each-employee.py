import pandas as pd

def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees["total_time"] = employees["out_time"] - employees["in_time"]
    selected = employees[["event_day", "emp_id", "total_time"]]
    grouped = selected.groupby(["event_day", "emp_id"]).sum().reset_index()
    return grouped.rename(columns={"event_day": "day"})