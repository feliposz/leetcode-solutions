import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    customers_and_orders = customers.merge(orders, how="left", left_on="id", right_on="customerId")
    non_ordering_customers = customers_and_orders[customers_and_orders["customerId"].isna()]
    return non_ordering_customers[["name"]].rename(columns={"name": "Customers"})