def solution(users, emoticons):
    discounts = [10, 20, 30, 40]
    m = len(emoticons)
    best_subscribers = 0
    best_sales = 0
    total_combinations = 4 ** m

    for comb in range(total_combinations):
        current_combo = []
        temp = comb
        for _ in range(m):
            discount_index = temp % 4
            current_combo.append(discounts[discount_index])
            temp //= 4

        subscribers = 0
        sales = 0
        for user_discount, min_purchase in users:
            total_cost = 0
            for discount, price in zip(current_combo, emoticons):
                if discount >= user_discount:
                    total_cost += price * (100 - discount) // 100
            if total_cost >= min_purchase:
                subscribers += 1
            else:
                sales += total_cost

        if subscribers > best_subscribers or (subscribers == best_subscribers and sales > best_sales):
            best_subscribers = subscribers
            best_sales = sales

    return [best_subscribers, best_sales]
