def filter_star(ratings, score):
    approved = dict()
    for k,v in ratings.items():
        if len(v) == score:
            approved[k] = v
    return approved if len(approved)>0 else "No results found!"

print(filter_star({
  'Luxury Chocolates': '*****',
  'Tasty Chocolates': '****',
  'Big Chocolates': '*****',
  'Generic Chocolates': '***'
}, 4) )

print(filter_star({
  'Luxury Chocolates': '*****',
  'Tasty Chocolates': '****',
  'Big Chocolates': '*****',
  'Generic Chocolates': '***'
}, 2))
