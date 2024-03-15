import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    filtered_animals = animals.loc[animals["weight"] > 100]
    sorted_animals = filtered_animals.sort_values(by="weight", ascending=False)
    selected_animals = sorted_animals[["name"]]
    return selected_animals
    # return animals.loc[animals["weight"] > 100].sort_values(by="weight", ascending=False)[["name"]]