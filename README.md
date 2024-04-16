# Israel Showell
# Start Date: 3-29-2024
# End Date: 4-9-2024
# Project: Iris Flowers Predictor
# Version: 1.1.0

# Description:
This is a medium-sized C++ program that will predict what kind of Iris Flower you have. 
It does this by taking the length and width of the Sepal and Petal that you have and the Iris-Dataset csv file for data to power its predictions.
This program exercises Machine Learning by taking in values for a new Iris flower.
It uses data from the famous iris dataset, and then processes the new input.
Afterwards, it will show how confidient it is in its prediction, and then add the new flower in as the
type it is most sure that it is. 

# Note:
The CSV file data goes, Sepal Width, Sepal Length, Petal Width, Petal Length, Iris Type

# C++ Concepts Used:
- Object-Oriented Programming (OOP)
- Control Structures
- Memory Management
- Function Overloading and Default Parameters
  
# Machine Learning Concepts Used:
- Statistical Analysis
- Gaussian (Normal) Distribution
- Likelihood Estimation
- Confidence Calculation
- Feature Extraction
- Predictive Modeling
  
# Note:
This is an upgraded version of the original version found here:
https://github.com/IsraelShowell/Iris-Flower-Predictor

# Version History:

# V-1.00: (3-29-24 - 4-9-24)
Initial Version <br>
Uploaded to Github

# V-1.10: (4-12-24)
Users can now only input one flower per session <br>
Added more comments explaining the logic and code

# Current Features as of V-1.10:
- Takes 4 variable values from the user about an Iris flower type 
- Uses the data from the famous Iris flower dataset to predict the likeihood of what type of flower the user may have
- Provides an accurate prediction of the user's flower type
- Dynamic allocation of memory for data structures
- Dynamic addition of new Iris types


# Future Features to Implement:
- Implement a cleaner UI

# Known Bugs in V-1.10:
- Error is suffered when trying to input two flowers in one session.
- Number of iris flowers becomes incorrect when trying to input two flowers in one session.
- Numbers may be wrong, but so far they all work out correctly


# Logic and Modeling used:
Note: I had ChatGPT give me a clearer recap on the logic I used.

Statistical modeling in the context of the functions mentioned involve various statistical methods and calculations, each serving a distinct purpose within the broader framework of understanding and predicting data behavior. Here's a breakdown of each function and the statistical modeling used in them:

# Sample Mean:
The sample mean is the average of a set of observations. In statistical modeling, it's used as an estimator for the population mean. It is calculated as the sum of all observations divided by the number of observations. The sample mean is crucial for setting the basis of various other statistical measures and models, serving as a central location measure.

# Sample Variance:

Sample variance measures the spread of data points around the mean. It is calculated by summing the squared differences of each observation from the mean and then dividing by the number of observations minus one,
n−1 provides an unbiased estimator of the population variance if the data is a sample from a larger population). Variance is fundamental in assessing the variability of data, which is critical in hypothesis testing and setting confidence intervals.

# Standard Deviation:

Standard deviation is the square root of the variance. It is used to measure the amount of variation or dispersion of a set of values. A low standard deviation indicates that the values tend to be close to the mean, while a high standard deviation indicates that the values are spread out over a wider range. In statistical modeling, standard deviation is used to assess the risk, variability, and volatility of different phenomena.

# Density Function:

A density function describes the probability distribution for a continuous random variable. The density function for a normal distribution, for example, can be calculated using the mean and standard deviation of the data. This function is key in probability theory and statistics, particularly in the context of inferential statistics where you're estimating population parameters.

# Likelihood:

Likelihood functions measure the goodness of fit of a statistical model to a sample of data for given values of the unknown parameters. It is used extensively in statistical inference, particularly in the methods of maximum likelihood estimation. The likelihood is proportional to the probability of observing the data given the parameters.

# Confidence Functions:

Confidence intervals provide a range of values which is likely to contain a population parameter, with a certain level of confidence. This is not directly related to a specific "confidence function" but rather to the process of constructing confidence intervals using sample statistics such as the mean and standard deviation. It's a way to express the reliability of an estimate.
These functions are integral components of statistical modeling, each contributing to the understanding, description, and prediction of data. They are applied according to the nature of the data and the specific requirements of the research question at hand, often integrated into more comprehensive statistical models and analyses.

