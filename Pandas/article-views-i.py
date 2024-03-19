import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    author_is_viewer = views[views["author_id"] == views["viewer_id"]]
    unique_authors = sorted(author_is_viewer["author_id"].unique())
    result = pd.DataFrame({"id": unique_authors})
    return result