# Probability and Statistics SAMPLE lab exam 2
## Q1
- Q1.A
  * ![Boxplot]("boxplot.png")
  * Yes, the boxplot suggests casein leads to the highest mean weight and horsebean the lowest.
- Q1.B
  * tapply(weight, feed, mean)
    *  casein horsebean   linseed  meatmeal   soybean sunflower 
    * 323.5833  160.2000  218.7500  276.9091  246.4286  328.9167 
  * tapply(weight, feed, var)
    *   casein horsebean   linseed  meatmeal   soybean sunflower 
    * 4151.720  1491.956  2728.568  4212.091  2929.956  2384.992 
  * Yes, sunflower results in the highest mean weight relative to other feed types.
- Q1.C
  * light_feeds = feed[weight < 159]
  * lin_or_sun = light_feeds[light_feeds=="linseed" | light_feeds == "sunflower"]
  * proportion = length(lin_or_sun) / length(light_feeds)
  * proportion = 0.2222222
## Q2
- ![Simulation]("simulation.png")
