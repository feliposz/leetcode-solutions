import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    selected = activity[["player_id", "event_date"]]
    grouped = selected.groupby("player_id").min().reset_index()
    return grouped.rename(columns={"event_date": "first_login"})