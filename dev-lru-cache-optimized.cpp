{
 "cells": [
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "___\n",
    "\n",
    "<a href='http://www.pieriandata.com'> <img src='../Pierian_Data_Logo.png' /></a>\n",
    "___"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# K Nearest Neighbors Project \n",
    "\n",
    "Welcome to the KNN Project! This will be a simple project very similar to the lecture, except you'll be given another data set. Go ahead and just follow the directions below.\n",
    "## Import Libraries\n",
    "**Import pandas,seaborn, and the usual libraries.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "## Get the Data\n",
    "** Read the 'KNN_Project_Data csv file into a dataframe **"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "**Check the head of the dataframe.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 23,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>XVPM</th>\n",
       "      <th>GWYH</th>\n",
       "      <th>TRAT</th>\n",
       "      <th>TLLZ</th>\n",
       "      <th>IGGA</th>\n",
       "      <th>HYKR</th>\n",
       "      <th>EDFS</th>\n",
       "      <th>GUUB</th>\n",
       "      <th>MGJM</th>\n",
       "      <th>JHZC</th>\n",
       "      <th>TARGET CLASS</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>1636.670614</td>\n",
       "      <td>817.988525</td>\n",
       "      <td>2565.995189</td>\n",
       "      <td>358.347163</td>\n",
       "      <td>550.417491</td>\n",
       "      <td>1618.870897</td>\n",
       "      <td>2147.641254</td>\n",
       "      <td>330.727893</td>\n",
       "      <td>1494.878631</td>\n",
       "      <td>845.136088</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>1013.402760</td>\n",
       "      <td>577.587332</td>\n",
       "      <td>2644.141273</td>\n",
       "      <td>280.428203</td>\n",
       "      <td>1161.873391</td>\n",
       "      <td>2084.107872</td>\n",
       "      <td>853.404981</td>\n",
       "      <td>447.157619</td>\n",
       "      <td>1193.032521</td>\n",
       "      <td>861.081809</td>\n",
       "      <td>1</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>1300.035501</td>\n",
       "      <td>820.518697</td>\n",
       "      <td>2025.854469</td>\n",
       "      <td>525.562292</td>\n",
       "      <td>922.206261</td>\n",
       "      <td>2552.355407</td>\n",
       "      <td>818.676686</td>\n",
       "      <td>845.491492</td>\n",
       "      <td>1968.367513</td>\n",
       "      <td>1647.186291</td>\n",
       "      <td>1</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>1059.347542</td>\n",
       "      <td>1066.866418</td>\n",
       "      <td>612.000041</td>\n",
       "      <td>480.827789</td>\n",
       "      <td>419.467495</td>\n",
       "      <td>685.666983</td>\n",
       "      <td>852.867810</td>\n",
       "      <td>341.664784</td>\n",
       "      <td>1154.391368</td>\n",
       "      <td>1450.935357</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>1018.340526</td>\n",
       "      <td>1313.679056</td>\n",
       "      <td>950.622661</td>\n",
       "      <td>724.742174</td>\n",
       "      <td>843.065903</td>\n",
       "      <td>1370.554164</td>\n",
       "      <td>905.469453</td>\n",
       "      <td>658.118202</td>\n",
       "      <td>539.459350</td>\n",
       "      <td>1899.850792</td>\n",
       "      <td>0</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "          XVPM         GWYH         TRAT        TLLZ         IGGA  \\\n",
       "0  1636.670614   817.988525  2565.995189  358.347163   550.417491   \n",
       "1  1013.402760   577.587332  2644.141273  280.428203  1161.873391   \n",
       "2  1300.035501   820.518697  2025.854469  525.562292   922.206261   \n",
       "3  1059.347542  1066.866418   612.000041  480.827789   419.467495   \n",
       "4  1018.340526  1313.679056   950.622661  724.742174   843.065903   \n",
       "\n",
       "          HYKR         EDFS        GUUB         MGJM         JHZC  \\\n",
       "0  1618.870897  2147.641254  330.727893  1494.878631   845.136088   \n",
       "1  2084.107872   853.404981  447.157619  1193.032521   861.081809   \n",
       "2  2552.355407   818.676686  845.491492  1968.367513  1647.186291   \n",
       "3   685.666983   852.867810  341.664784  1154.391368  1450.935357   \n",
       "4  1370.554164   905.469453  658.118202   539.459350  1899.850792   \n",
       "\n",
       "   TARGET CLASS  \n",
       "0             0  \n",
       "1             1  \n",
       "2             1  \n",
       "3             0  \n",
       "4             0  "
      ]
     },
     "execution_count": 23,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# EDA\n",
    "\n",
    "Since this data is artificial, we'll just do a large pairplot with seaborn.\n",
    "\n",
    "**Use seaborn on the dataframe to create a pairplot with the hue indicated by the TARGET CLASS column.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<seaborn.axisgrid.PairGrid at 0x1197505f8>"
      ]
     },
     "execution_count": 4,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "text/plain": [
       "<matplotlib.figure.Figure at 0x119750630>"
      ]
     },
     "metadata": {},
     "output_type": "display_data"
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Standardize the Variables\n",
    "\n",
    "Time to standardize the variables.\n",
    "\n",
    "** Import StandardScaler from Scikit learn.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "** Create a StandardScaler() object called scaler.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "** Fit scaler to the features.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "data": {
      "text/plain": [
       "StandardScaler(copy=True, with_mean=True, with_std=True)"
      ]
     },
     "execution_count": 7,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "**Use the .transform() method to transform the features to a scaled version.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "**Convert the scaled features to a dataframe and check the head of this dataframe to make sure the scaling worked.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>XVPM</th>\n",
       "      <th>GWYH</th>\n",
       "      <th>TRAT</th>\n",
       "      <th>TLLZ</th>\n",
       "      <th>IGGA</th>\n",
       "      <th>HYKR</th>\n",
       "      <th>EDFS</th>\n",
       "      <th>GUUB</th>\n",
       "      <th>MGJM</th>\n",
       "      <th>JHZC</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>1.568522</td>\n",
       "      <td>-0.443435</td>\n",
       "      <td>1.619808</td>\n",
       "      <td>-0.958255</td>\n",
       "      <td>-1.128481</td>\n",
       "      <td>0.138336</td>\n",
       "      <td>0.980493</td>\n",
       "      <td>-0.932794</td>\n",
       "      <td>1.008313</td>\n",
       "      <td>-1.069627</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>-0.112376</td>\n",
       "      <td>-1.056574</td>\n",
       "      <td>1.741918</td>\n",
       "      <td>-1.504220</td>\n",
       "      <td>0.640009</td>\n",
       "      <td>1.081552</td>\n",
       "      <td>-1.182663</td>\n",
       "      <td>-0.461864</td>\n",
       "      <td>0.258321</td>\n",
       "      <td>-1.041546</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>0.660647</td>\n",
       "      <td>-0.436981</td>\n",
       "      <td>0.775793</td>\n",
       "      <td>0.213394</td>\n",
       "      <td>-0.053171</td>\n",
       "      <td>2.030872</td>\n",
       "      <td>-1.240707</td>\n",
       "      <td>1.149298</td>\n",
       "      <td>2.184784</td>\n",
       "      <td>0.342811</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>0.011533</td>\n",
       "      <td>0.191324</td>\n",
       "      <td>-1.433473</td>\n",
       "      <td>-0.100053</td>\n",
       "      <td>-1.507223</td>\n",
       "      <td>-1.753632</td>\n",
       "      <td>-1.183561</td>\n",
       "      <td>-0.888557</td>\n",
       "      <td>0.162310</td>\n",
       "      <td>-0.002793</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>-0.099059</td>\n",
       "      <td>0.820815</td>\n",
       "      <td>-0.904346</td>\n",
       "      <td>1.609015</td>\n",
       "      <td>-0.282065</td>\n",
       "      <td>-0.365099</td>\n",
       "      <td>-1.095644</td>\n",
       "      <td>0.391419</td>\n",
       "      <td>-1.365603</td>\n",
       "      <td>0.787762</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "       XVPM      GWYH      TRAT      TLLZ      IGGA      HYKR      EDFS  \\\n",
       "0  1.568522 -0.443435  1.619808 -0.958255 -1.128481  0.138336  0.980493   \n",
       "1 -0.112376 -1.056574  1.741918 -1.504220  0.640009  1.081552 -1.182663   \n",
       "2  0.660647 -0.436981  0.775793  0.213394 -0.053171  2.030872 -1.240707   \n",
       "3  0.011533  0.191324 -1.433473 -0.100053 -1.507223 -1.753632 -1.183561   \n",
       "4 -0.099059  0.820815 -0.904346  1.609015 -0.282065 -0.365099 -1.095644   \n",
       "\n",
       "       GUUB      MGJM      JHZC  \n",
       "0 -0.932794  1.008313 -1.069627  \n",
       "1 -0.461864  0.258321 -1.041546  \n",
       "2  1.149298  2.184784  0.342811  \n",
       "3 -0.888557  0.162310 -0.002793  \n",
       "4  0.391419 -1.365603  0.787762  "
      ]
     },
     "execution_count": 9,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Train Test Split\n",
    "\n",
    "**Use train_test_split to split your data into a training set and a testing set.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 10,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": 11,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Using KNN\n",
    "\n",
    "**Import KNeighborsClassifier from scikit learn.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 12,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "**Create a KNN model instance with n_neighbors=1**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 13,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "**Fit this KNN model to the training data.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 14,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "data": {
      "text/plain": [
       "KNeighborsClassifier(algorithm='auto', leaf_size=30, metric='minkowski',\n",
       "           metric_params=None, n_jobs=1, n_neighbors=1, p=2,\n",
       "           weights='uniform')"
      ]
     },
     "execution_count": 14,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Predictions and Evaluations\n",
    "Let's evaluate our KNN model!"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "**Use the predict method to predict values using your KNN model and X_test.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 24,
   "metadata": {
    "collapsed": false
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "** Create a confusion matrix and classification report.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 16,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": 17,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[[112  40]\n",
      " [ 34 114]]\n"
     ]
    }
   ],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": 18,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "             precision    recall  f1-score   support\n",
      "\n",
      "          0       0.77      0.74      0.75       152\n",
      "          1       0.74      0.77      0.75       148\n",
      "\n",
      "avg / total       0.75      0.75      0.75       300\n",
      "\n"
     ]
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Choosing a K Value\n",
    "Let's go ahead and use the elbow method to pick a good K Value!\n",
    "\n",
    "** Create a for loop that trains various KNN models with different k values, then keep track of the error_rate for each of these models with a list. Refer to the lecture if you are confused on this step.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 25,
   "metadata": {
    "collapsed": true
   },
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "**Now create the following plot using the information from your for loop.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 20,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<matplotlib.text.Text at 0x11cbdb710>"
      ]
     },
     "execution_count": 20,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "iVBORw0KGgoAAAANSUhEUgAAAmsAAAGJCAYAAADVKHTwAAAABHNCSVQICAgIfAhkiAAAAAlwSFlz\nAAALEgAACxIB0t1+/AAAIABJREFUeJzt3XmcU9X9//HXTWZNmHEdAVestqeLS61WAaFuLLUFpbZf\nZal+a8WKVkUQquJuq7aCINriUm2rra1aqyB+WxGqdUG/rmihPz1qFcpXBZFSlsnsub8/kkBmJpNl\nJstN8n4+HjyY3Nyb+8nJvTefnHvv5ziu6yIiIiIi3uQrdAAiIiIi0jMlayIiIiIepmRNRERExMOU\nrImIiIh4mJI1EREREQ9TsiYiIiLiYRWFDkBEiosxJgysBMKACzjR/8dZa/+Vx/UGgM3Aedba11Is\nexZQaa29I1fxpVj/1cBu1toLo48rgd8DewAnWWs3x837FLDEWvuzLq9xMTDcWjsuyXp+Day01s7N\nwdsQkQJRsiYimXKBY621mwq93mgCcxswNMWyw4gkegVnjAkAjwBbgZHW2tYus/wCuB74WZfpk4Hz\ncx+hiHiNkjURyZQT/deNMeYYYD7QSKTn6xLgprjHRwJnAhcA7cB64Hxr7XvRXqFdgc8Aj1trL0u2\nXmOMH9gX2Bh9vAdwJ5HeqgHAGuBUIonaScAIY0yTtfZ2Y8ws4BQil4KsJtI7t67Le1kO3GytfST6\n+MboU7cA9wG7RR//2Vp7VcpWi7zGzsCfgdestRf0MNtC4BZjzNHW2uXR5Y4BsNb+1RjjAPOAo4C6\naJtMtta+2GVdYWB3a+2/uz42xowBrgAqgRAw01r7v+m8BxHJP12zJiK98bQx5vXovxXGmD/FPfcl\n4DRr7WFAS5fHw4AZwDHRx38AFsUtW2utPThBoha/3jeMMR8C7xDpbTsz+tx44AVr7dHW2gOAJuB0\na+1C4DFgXjRROx04GDjSWvsV4C/APQnW9cvYaxtjfMB3gbuBs4F/WmuPAL4GHGiMqUujzQYCfwO+\nCFzX00zW2o7ouifHTT4bWBD9+yhgoLV2iLX2ICKJ46UJXqrr8DRu9L0cCNwAnGitPRw4B3jEGFOb\nxnsQkQJQz5qI9Eay06BrrbX/18PjrwMPxnp7rLX3GmNuMcbsF33++XTWa4z5MpEeqhestZ9GX+tW\nY8wwY8w04LNEksREvUVjgK8CrxljIPKjNVGi8hAwO9pjdwTwrrX2n8aYJ4D/ica8DLjUWrs1RdwA\nJwNTiPQuPmyMOc5aG+5h3ruAfxhjgkA1MAo4N/o+/9cYc6UxZgpwAHAssCXBayTs/QRGEul5jPXS\nQaSX80A8cqpYRDpTz5qI9EZPiQDAtiSPEx1zfEROxyVaNuF6rbVvANOBe4wx+wIYY34GXAt8QuR0\n6NIe4vQDP7PWHhbt3TsCGN51JmttCPgjMAn4HpHeLqy1rwL7R9exH/CKMWZwirgBfm2t/RUwlcjp\ny3k9zRg9JbsUmACcDjwcSwiNMd8E/odIT9lC4I4e3iex6dEbGmL8wF+ttV+Ja4OhwKo03oOIFICS\nNRHJpyXAacaY3QGMMWcCn1pr38v0hay1DwAvErmGDCK9T7dYa+8HPiXSg+SPPtfOjoRwCTA57tTl\nT4icSkzkbiKJ2hDgT9GYbwSustY+Zq29CPgH8Lk0Qm6Jxt1C5Fq6M4wxE5PMfzuRRPEMIjcdxIwA\nHrPW3gm8BoyLe5/xPiGSiAJ8O276U8AoE+1WNMZ8A3gTqEnjPYhIAeg0qIhkyiVy7VhH9HGsdMcs\nIteJ9chau8wYMw94KnoKbgPwzbjXTbXers4H3jTGjCTSq3azMeYqIsnZc0RO7UHkurTbjDFYa39m\njNkL+N/oRff/IpKQJYr3dWNMG5Gerdhdm7cA9xpj/k4kAXuTyLV3GGNWAGdZa19P0Q7vGWPOBn5t\njFllrf17gnmeMcbsRiSZ/UfcU3cAvzfGvAF0AM/SORmLmQosMMZsItJL93H0df+fMeYHwAPRfK0d\nGGutTfrZiUjhOK6b6vgoIiIiIoWS05616C/nBcChQDOR28vfj3t+ApFff21ECjmeF51+KZFb7SuB\nBdbaX+cyThERERGvyvU1a+OAamvtUOAyYHtVbWNMDZHb14+x1g4HdjbGjInWExoSXeZYYJ8cxygi\nIiLiWblO1oYBTwBYa19ix8WuELnWY2j0YluI9PI1A6OBVcaYWG2kx3Mco4iIiIhn5TpZqycydl9M\ne7S4JNZa11q7AcAYcwEQtNYuA3YHDge+Q6Su0O9zHKOIiIiIZ+X6btAtROoJxfjii0BGr2m7iUgB\ny1OikzcCb1lr24F3jDHNxpjdY4UvE3Fd13WcZGWfRERERDwjo6Ql18naciLVwh+OFo3sWh37LqDJ\nWjsubtrzwIXAPGPMnkTGE9yYbCWO47BhQzoFxMtLQ0Od2qULtUliapfE1C6JqV26U5skpnZJrKEh\nnRHqdsh1svYoMDI6IDLAmdE7QINEijmeCTxnjHmaSA2l+dbaRcaYrxljXiaSeZ5nrVV9ERERESlL\nOU3WoknWuV0mv5Nq/dbaS3IWlIiIiEgR0XBTIiIiIh6mZE1ERETEw5SsiYiIiHiYkjURERERD1Oy\nJiIiIuJhStZEREREPEzJmoiIiIiHKVkTERER8TAlayIiIiIepmRNRERExMOUrImIiIh4mJI1ERER\nEQ9TsiYiIiLiYUrWRERERDxMyZqIiIiIhylZExEREfEwJWsiIiIiHqZkTURERMTDlKyJiIiIeJiS\nNREREREPU7ImIiIi4mFK1kREREQ8TMmaiIiIiIcpWRMRERHxMCVrIiIiIh6mZE1ERETEw5SsiYiI\niHiYkjURERERD6sodACF4GzZTPXiRfjWryPcfwAtY0/Grd+p0GGJiIiIdFN2yVpg3mwC8+fihBq3\nT+t3+SWEpk4nNG1mASMTERER6a6skrXAvNkEb/xxt+lOqHH7dCVsIiIi4iVlc82as2Uzgflzk84T\nmD8XZ+uWPEUkIiIiklrZJGvVixd1OvWZiBNqpHrxojxFJCIiIpJa2SRrvvXrsjqfiIiISD6UTbIW\n7j8gq/OJiIiI5EPZJGstY0/GDQSTzuMGgrSMPTlPEYmIiIikVjbJmlu/E6Gp05POE5o6HbeuPk8R\niYiIiKRWVqU7YmU5utZZcwNB1VkTERERTyqrZA0iCVvT5HN4fdbjPPPgpxw7fjcOu36setRERETE\nk8ouWQNw6+rZ79qJfPNCH/vuG8atLnREIiIiIomVZbIGsOuusOuu4UKHISIiIpJU2dxgICIiIlKM\nlKyJiIiIeJiSNREREREPU7IGuG6hIxARERFJrKyTtUceqcCYfixeXLb3WYiIiIjHlXWy1q+fy6ZN\nDqtXl3UziIiIiIfltEvJGOMAC4BDgWZgsrX2/bjnJwBTgTZgpbX2vLjn9gBeBUZYa9/JRXyDBkXO\nf65e7eTi5UVERET6LNddSuOAamvtUOAyYG7sCWNMDXAdcIy1djiwszFmTPS5CuAOIJTL4PbdN4zj\nuOpZExEREc/KdZYyDHgCwFr7EnBE3HMtwFBrbUv0cQWR3jeAOcDtwEe5DK6mBgYOVLImIiIi3pXr\nLKUe2Bz3uN0Y4wOw1rrW2g0AxpgLgKC1dpkx5nvAJ9bapUDOz0/ut1+YTz5xaG3N9ZpEREREMpfr\n2yC3AHVxj33W2u1jPEWvabsJ+CxwSnTymUDYGDMS+DJwnzHmJGvtJ7kI8Ne/bqK+Hip0Q6iIiIh4\nUK5TlOXAGOBhY8xgYGWX5+8Cmqy142ITrLXHxP42xjwNnJNOotbQUJdqlh6W69ViRaO37VLK1CaJ\nqV0SU7skpnbpTm2SmNql73KdrD0KjDTGLI8+PjN6B2gQeI1IL9pz0aTMBeZbaxfFLZ92udoNG7Zm\nKeTS0dBQp3bpQm2SmNolMbVLYmqX7tQmialdEss0gc1psmatdYFzu0yOL8ORdP3W2uOzHpSIiIhI\nEdFtkCIiIiIepmSNyNigmzYVOgoRERGR7pSsASedVMuhh/YjHE49r4iIiEg+KVkDBgxwaW52WL9e\nw06JiIiItyhZAwYNinSpaSQDERER8RplJ2hAdxEREfEuJWtEhpwC9ayJiIiI9yg7IXIatKbGpalJ\nPWsiIiLiLRoRE9hrL5fVq7fhU+oqIiIiHqNkDXCcyD8RERERr1FfkoiIiIiHKVkTERER8TAlayIi\nIiIepmvWosJh+PhjB9eFvfd2Cx2OiIiICKCete3ee8/HYYf14+abqwodioiIiMh2Stai9t03jOO4\nKowrIiIinqLMJKqmBgYOVLImIiIi3qLMJM5++4X56COHlpZCRyIiIiISoWQtzqBBLq7rsHatKuSK\niIiINyhZi/OFL3Rw0EEdhEJK1kRERMQbVLojzpQpbUyZ0lboMERERES2U8+aiIiIiIcpWRMRERHx\nMCVrIiIiIh6mZE1ERETEw5SsdbFuncNTT/nZurXQkYiIiIgoWevmnnsqGT8+wMqV/kKHIiIiIqJk\nratBg1wAVq9WrTUREREpPCVrXey3XxiANWvUNCIiIlJ4yki6GDQokqxpQHcRERHxAmUkXQwc6FJV\n5SpZExEREU/QcFNd+P1w4ont7LKLW+hQRERERJSsJfLLXzYXOgQRERERQKdBRURERDxNyZqIiIiI\nhylZExEREfEwJWsiIiIiHqZkrQdLl/pZvFj3X4iIiEhhKRvpwcyZNTgOjB3bXuhQREREpIypZ60H\n++0X5qOPHFpaCh2JiIiIlDMlaz0YNMjFdR3WrtWA7iIiIlI4StZ6oDFCRURExAuUifRAyZqIiIh4\ngTKRHnzpS2HGj2/jgAPChQ5FREREypjuBu3B5z4X5tZbNUaoiIiIFJZ61kREREQ8TMmaiIiIiIcp\nWRMRERHxsJxes2aMcYAFwKFAMzDZWvt+3PMTgKlAG7DSWnueMaYC+BUwCKgCrrfWLs5lnCIiIiJe\nleuetXFAtbV2KHAZMDf2hDGmBrgOOMZaOxzY2RgzBvgu8Km19mvAicDPcxxjj9ascbj11ipeeslf\nqBBERESkzOU6WRsGPAFgrX0JOCLuuRZgqLU2NqBTBZHet4eAK+Pia8txjD1au9bHT35SzVNPKVkT\nERGRwsh16Y56YHPc43ZjjM9aG7bWusAGAGPMBUDQWrssNqMxpg74I3B5jmPskQrjioiISKHlOlnb\nAtTFPfZZa7dXmY1e03YT8FnglLjp+wCPAD+31j6Y4xh7NHCgS1WVq2RNRERECibXydpyYAzwsDFm\nMLCyy/N3AU3W2nGxCcaY/sAS4IfW2qfTXVFDQ13qmXph//1hzRp/zl4/14o17lxSmySmdklM7ZKY\n2qU7tUliape+c1zXzdmLx90Nekh00pnA4UAQeA14BXgu+pwLzAeOA04F3gac6PQT465tS8TdsGFr\n1uMHmDixlmXLKnj33a3stFNOVpEzDQ115KpdipXaJDG1S2Jql8TULt2pTRJTuyTW0FDnZDJ/TnvW\notelndtl8jsp1r8IuChnQWXo1FPbGDq0vdBhiIiISJnS2KApjBunRE1EREQKR1fOi4iIiHiYkjUR\nERERD1OyJiIiIuJhStZEREREPEzJWhoeeqiCCy6ooSVZ8RARERGRHFCyloblyyt48MFK1q7NqCyK\niIiISJ8pWUuDxggVERGRQlH2kQYlayIiIlIoyj7SoGRNRERECkXZRxqUrImIiEihaLipNOy8M9x4\nYzNf+EK40KGIiIhImVGylgbHgbPOait0GCIiIlKGdF5PRERExMOUrImIiIh4mJI1EREREQ9TsiYi\nIiLiYUrW0rRtG0yZUsNPf1pV6FBERESkjChZS1NtLTz+eAVPP60baEVERCR/lKylye+HffcNqzCu\niIiI5JW6iTLwxb3/w+7vLcR3w2qq9htAy9iTcet3KnRYIiIiUsKUrKUpMG82Dz4/lxoa4ZbItH6X\nX0Jo6nRC02YWNjgREREpWUrW0hCYN5vgjT/uNt0JNW6froRNREREckEXYKXgbNlMYP7cpPME5s/F\n2bolTxGJiIhIOVGylkL14kU4ocak8zihRqoXL8pTRCIiIlJOlKyl4Fu/LqvziYiIiGRCyVoK4f4D\n0pqvY4/05hMRERHJhJK1FFrGnowbCCadZxtB/nvxeNatc/IUlYiIiJSLtJI1Y8zRxpgpxphqY8zX\nch2Ul7j1OxGaOj3pPH8YdAkLn9qV4cODPPhgBa6bp+BERESk5KVM1owxU4GfANOBfsCdxpgZuQ7M\nS0LTZtJ42ZXdetjcQJDGy67k5JcuYvbsZtrb4YILajn99FpaWnbM52zZTM399xGYexM199+Hs2Vz\nnt+BiIiIFKt06qx9DzgKeMlau9EY81XgZWBOLgPzmtC0mTRNPofqxYvwrV9HuH90BIO6ehzgv/+7\njeOPb2fatBr69XOpro4sF5g3O1LaI+6OUhXTFRERkXSlk6x1WGtbjTGxx81AR+5C8i63rp7miaf3\n+Pw++7j88Y9NNDVFHquYroiIiPRVOtesPWOMmQMEjTHjgMeAp3IbVvFyHAgEVExXREREsiOdZG0m\n8C7wJnAG8Gci169JEiqmKyIiItmQzmnQS6y1NwJ3xiYYY24AZuUsqhKgYroiIiKSDT0ma8aYnwJ7\nACcZYz7bZZnBKFlLKt1iuunOJyIiIuUp2WnQPwHPAI3R/2P/lgDfzH1oxS2dYrpuIEjL2JPzFJGI\niIgUox571qy1rwCvGGMWWmu3FwYzxjjA/vkIrpjFiukmuhs0JjR1Om5dfR6jEhERkWKTzjVrp0ev\nUYvvJloNHJCTiEpIrCxH1zpr4UCQJtVZExERkTSkk6xdDBwKXE/kOrVjgZE5jKmkxBfTXfHnDXzM\nAI746Rjq91aPmoiIiKSWTrL2ibX2A2PM34GDrbW/Mcacn+vASkmsmO4XJsIXCh2MiIiIFJV06qw1\nGmOOA/4OjDXGDAB2yW1YIiIiIgLpJWsXAmOBJ4DdgLeB23IZlIiIiIhEpDwNaq1dxY4RC74NYIwZ\nmsugRERERCQiWVHcIcA8YCPwfWvtemPMIOAmYAwQyEuEIiIiImUs2WnQO4A/AG8BVxljzgL+AbQD\nX8xDbCXr97+vYPjwAB9/7BQ6FBEREfG4ZKdBK62186NFcNcAxwAjrLUv5ie00rVtm4O1fpYureCM\nM9oKHY6IiIh4WLKetRYAa60LhIETlKhlx6hR7QA8+WQ6lVNERESknCXLFty4v/9trV2f6YtHe+UW\nECmq2wxMtta+H/f8BGAq0AastNael2qZUjBokIsxHTz7rJ9QCAK6+k9ERER6kCxZG2iMuSrB3wBY\na69L4/XHAdXW2qHGmKOAudFpGGNqgOuAg6y1LcaY3xtjxgCVPS1TSkaObOfnP6/muef8jB7dUehw\nRERExKNS3WDgRP/F/x37l45hROqzYa19CTgi7rkWYKi1tiX6uIJIT1qyZUrGqFGRBG3FCn+BIxER\nEREv67FnzVp7bRZevx7YHPe43Rjjs9aGo9fCbQAwxlwABK21y4wxp/W0TBbi8YyvfrWDl17axv77\nu6lnFhERkbKV6yvctwB1cY87JV3R69NuAj4LnJLOMj1paKhLNYvnDBiQ+3UUY7vkmtokMbVLYmqX\nxNQu3alNElO79F2uk7XlRAroPmyMGQys7PL8XUCTtXZcBssktGHD1iyEW1oaGurULl2oTRJTuySm\ndklM7dKd2iQxtUtimSawKZM1Y8xPrLVX9DKeR4GRxpjl0cdnRu8ADQKvAWcCzxljniZy9+n8RMv0\nct0iIiIiRS+dnrWxxpgro9eYZSS6zLldJr+Txvq7LiMiIiJSltJJ1jYCbxtjXgeaYhOttd/PWVRl\nJByGN9/04Tjw5S+X1D0UIiIikgXpJGv35jyKMrZ2rcPo0UFGjWrnd79rSr2AiIiIlJVkddYAsNbe\nS+T6sjpgF+DN6DTJgv326zyagYiIiEi8lMmaMeZ0YBGwP7Af8IgxRqdAs2jUqHaamx2ef14FckVE\nRKSzlMkacDFwpLX2YmvtNOBIYHpuwyovsdEMlizRwO4iIiLSWTrJmt9auzH2wFr7KaAr4bPoiCM6\n2HXXMEuXVuBqQAMRERGJk05XzpvGmFuAe6KPzwLezF1I5cfvh/POa8Pnc2ltherqQkckIiIiXpFO\nsnY2cA3wKyI9cX8FzsthTGXpwgtbCx2CiIiIeFA6ydoCa61GERAREREpgHSuWTvIGNMv55GIiIiI\nSDfp9Ky5wL+MMZbOIxgcn7OoRERERARIL1mbBbTlOhARERER6S6dZO0ma+1Xch6JAHDrrVU8+GAF\nS5eGCAQKHY2IiIgUWjrXrK03xgw3xqigRB5s3gzvvuvXaAYiIiICpJesHQE8A4SMMR3GmLAxpiPH\ncZUtjWYgIiIi8VJmBNbahnwEIhGdRzNowXEKHZGIiIgUUo89a8aYc+P+/lKX527JZVDlzO+HE07o\nYN06H3//ezodnyIiIlLKkmUDZ8f9/dsuz30tB7FI1OjR7QCsWKHr1kRERMpdstOgTg9/S46NGNHO\nypXb6N9fo7qLiIiUu3SvYlfWkEeBAAQCLs6WzVQvXoRv/TrC/QfQMvZk3PqdCh2eiIiI5FGyZE0J\nWgEF5s0mMH8uTqhx+7R+l19CaOp0QtNmFjAyERERyadkydqXjDHvR//eK+5vBxiY27DKW2DebII3\n/rjbdCfUuH26EjYREZHykCxZ+1zeopDtnC2bCcyfm3SewPy5NE0+B7euPk9RiYiISKH0mKxZa9fk\nMxCJqF68qNOpz0ScUCPVixfRPPH0PEUlIiIihaJCXh7jW78uq/OJiIhIcVOy5jHh/gOyOp+IiIgU\nNyVrHtMy9mTcQDDpPG4gSMvYk/MUkYiIiBSSkjWPcet3IjR1etJ5QlOn6+YCERGRMpFuUVzJo1hZ\njq511txAUHXWREREyoySNY8KTZtJ0+RzqF68iGcf2oAzcABf/dkYqFePmoiISDlRsuZhbl09zRNP\n58iJhY5ERERECkXXrImIiIh4mJI1EREREQ9TsiYiIiLiYUrWRERERDxMyVoRueqqak44IYDrFjoS\nERERyRcla0Vk40aHlSv9rFypj01ERKRc6Fu/iIwe3Q7AkiWquCIiIlIulKwVkeOOa6eiwuXJJ5Ws\niYiIlAsla0Wkrg6GDOngzTf9rFvnFDocERERyQMla0Vm9Oh2/H6XN97QRyciIlIOdD6tyIwf38ap\np7ax886FjkRERETyQclakdE47iIiIuVF59JEREREPEzJmoiIiIiHKVkTERER8TAla0WqqQmWLvWz\nerVKeIiIiJQyJWtFaunSCiZNCvDQQ5WFDkVERERyKKd3gxpjHGABcCjQDEy21r7fZZ4A8CTwfWvt\nO8aYCuBeYBDQDpxtrX0nl3EWo+OOa6ey0mXp0gp+9KPWQocjIiIiOZLrnrVxQLW1dihwGTA3/klj\nzOHAM8Bn4iZ/A/Bba48GfgzckOMYi5JGMxARESkPuU7WhgFPAFhrXwKO6PJ8FZGE7u24ae8AFdFe\nuZ0AdRv1YNSoyMDuGitURESkdOU6WasHNsc9bjfGbF+ntfZFa+2HQHzX0DZgfyIJ3J3ArTmOsWgp\nWRMRESl9uf6W3wLUxT32WWvDKZaZBjxhrb3cGLMX8LQx5iBrbdIetoaGumRPl6SGBrjwQhg8uKLH\n91+O7ZKK2iQxtUtiapfE1C7dqU0SU7v0Xa6TteXAGOBhY8xgYGUay2xix6nP/xCJ0Z9qoQ0btvY2\nxqJ2xRWR/zds6P5cQ0Nd2bZLT9QmialdElO7JKZ26U5tkpjaJbFME9hcJ2uPAiONMcujj880xkwA\ngtbau+Pmc+P+ngf8yhjzLFAJXGatbcpxnCIiIiKelNNkzVrrAud2mdytDIe19vi4vxuB03IZl4iI\niEixUFFcEREREQ9TslZCXDf1PCIiIlJclKyVANeFKVNq+Pa3awsdioiIiGSZkrUS4DiwYYPD889X\n8PHHGs1ARESklChZKxGjR0cK5C5dqgK5IiIipUTJWonQaAYiIiKlSclaiRg0yMWYDp591k8oVOho\nREREJFuUrJWQWO/aW2/pYxURESkV+lYvIeef38rbb2/j8MNTDb8qIiIixUIXOJWQXXYpdAQiIiKS\nbUrWSpCzZTPVixfBtk3U9NuFlrEn49bvVOiwREREpBeUrJWYwLzZBObPxQk1AlAH9Lv8EkJTpxOa\nNrOwwYmIiEjGlKyVkMC82QRv/HG36U6ocft0JWwiIiLFRTcYlAhny2YC8+cmnScwfy7O1i15ikhE\nRESyQclaiahevGj7qc+eOKHGyLVsIiIiUjSUrJUI3/p1WZ1PREREvEHJWokI9x+Q1flERETEG5Ss\nlYiWsSfjBoJJ53EDQVrGnpyniERERCQblKyVCLd+J0JTpyedJzR1Om5dfZ4iEhERkWxQ6Y4SEivL\nEV9nDSAcCNJUInXWYgV/fevXEe4/QAV/RfIonwW3872vl/qxpVDtma/i7CX/+bmuW+gYssHdsGFr\noWPwDGfrFqoXL6Ju2ya2xnaSEuhR61rwFyKndjMp+NvQUIe2le7ULompXXbIxv7nxXVla31e3laK\nsT29vL5saGioczKZ33/NNdfkKJS8uiYUai10DN5RXU37wYcS/PoIthzweaiuLnREfRYr+Ou0tXWa\n7rS1UfX8s1BRQduQo1O+TjBYjbaV7tQuialdIrK1/3ltXdlcn1e3lWJtT6+uL1uCweprM5lfPWsl\nrKdfeq4LTkY5fWE5Wzaz2yGfT1pHzg0E2bjSpuxB9PKv30JSuySmdsnu/ueldWV7fV7cVoq5Pb24\nvmzKtGdNNxiUmQ8/dDjllFpefbV4PnoV/BUpnHzuf/ne10v92FLq7Vnqn1+84vnGlqz44AMfL7zg\n5wc/qGXTpkJHkx4V/BUpnHzuf/ne10v92FLq7Vnqn188JWtlZtiwDmbMaOX//s/H1Kk1FMNZcBX8\nFSmcd7bumdZ82dj/8r2vl/qxpXW30m7PUv/84ilZK0PTp7cyfHg7TzxRyZ13VhY6nJRU8Fck/xob\nYdasao5ous6ZAAAgAElEQVT9xUSa/PnZ//K9r5fysWXlSh9fv3sC2yjd9izlz68rJWtlyO+HBQua\naWgIc9111bz1lrc3AxX8FcmvF17wc+yxQe6+u4r+n+3H2kkXJ50/W/ufW78T/zw1+brWTLo4a/u6\nW78TK8fOSDpPMR5bFiyoZPToAC/bXfnLl3+UdN5svr98H6vL6btBpTtKWLJbyfv1g0MOCXPAAS7f\n+EY7jhO5s6bm4YeoWrYE//v/pGPQIKiuyW/QPWgdfDS/+m0tX2p8mSp23KLdXBGk5ZJL066l49Xb\n6wtN7ZJYvtol3/tesvVdfXU1M2bUsHUr/PCHrdx1VzN13xgKFRVUvv5apxIJ2wgyt99V7PmLiwkE\n+h7X5s1wwrUj2bi5kuHVL+Pv2LGutuogV3VczeWNl3PaaW1UVfV9fevWORx/9Qi2tUbW52vfsb6O\n2iBvjptF7U+SJ3MxmW4rvf3M01lu7Vofr73m5+67mzjuqqN6/OzeOGkW/W5M7/2l6709h3H7PQEG\nOy9T6XZe37sTZ1F1bXbX1zbk6ITvr8kf5F9nXobvSm/WWVPpDtkuk1vJvV5U8Ikn/JxxRoCJYzZy\nx4gH4eN1XPGLfVlc/R1e/IcfX5qdg168vd4L1C6J5aNdvFZAdPbsKhYurODWW5s5/PBwp2W7Ftye\n/+F/ceXsBk44oZ37729Kez9MxHXhrLNqePzxSqZNa2HW+Z92q0h/2Y0N3H13FRMmtDF/fnPvVxbV\n3AzXXFPNZz8bZvKpG7evr2OPARxz2wTsxzvz8suN9O+f+nsyH8fbdJdzXQiFIBh3hjD22fnWr2ND\nxQC+csMkdtu/H889F8LvTyvstEyfXs3vflfF3XPXc6rvT9Rt28Sqf+/K0LmTOGhIgIULm7JaOuqd\nd3x87nPhTu9v+wgGHu5Ry7R0h5K1EpbuwSNWVLAnjZddWdCEzXVhxIgAq1b5ePbZEMZEvkAuvLCG\nBx6oZMmSRg47LJziVSKUlCSmdkks1+2S730vnfVtPn8mHR1Qk6STJ9Yu4TBMnFhLKAS//W0TO/Vh\ndJ/WVpg+vYa1ax3+9KcmKhIMhtjSAmPGBHjzTT+33trE+PHtvV9hCvfeW8nMmTVMmdLKdde1pJw/\n18fbbG8rF19czW9/W8Xttzfx7W9npx3XrHEYMiTIoEHh7UlgrF0mTarl+ef9PPNMI4MGZSfveP11\nH1//epALL2zhiiuK68yAkjXZLp2DRzEUFVyzxuHEEwMMH97BnXfu+DW9eHEFZ51Vy/TpLVx6aXo7\nqpKSxNQuieWyXYq5gGh8u2zZAoEACZOrTLkuNDWR9JTq6tUOJ5wQ5KCDOrLeSxOvtRWOOirIv//t\npNW7lsvjbS62lX/9y2Hw4M6JVV/FetXiE8BYu6xe7VBbS1q9lOmaOLGWZcsqeOSREMOGdWTtdfNB\nRXElI8VQVHC//VxefbWRH/+486/b445rp6rK5YMPtBlL8SmVAqL19dlJ1CAyskqqa98GDXJ59NEQ\nDz2Uu0QNoKoKLrqolaYmh1/8IgsXyJH+Z9DxYOfPIBef3b77ukyY0MZ77/l5+um+Z2offeTwwAOV\nHHhgB+PGde+pGzTIzWqi9vrrPpYtq2DIkHaOPjq9RG3t2iIauqcLfcuVuWIpKhgIwB57dN7R+/WD\nN95o7NTbJlIsVEC09w45JNyrIY/b2yM9gemaMKGNvfYKc999lWzNQgdrum3bvnZ9r5bL9LObNq2V\nP/4xxAkn9L1XauBAl/vvb+L661uyeg1cT+bMiWwAM2e2ppW0X3ttNcOHB7G2ONOe4oxasqbYiwru\nvntJnMaXMpTvfa9pZ+/t6/m+Cuemm6o4/vgg776b3ldfVRXMm9fMX/4Soq6u7+tPt21r9u/fq+Uy\n/ez23tvlmGM6stJD6Thw3HEdHHdc7k9H9qZX7Stf6SAUcpg8uYbG5J2UnqRkrcyVU1FBES9JZ99r\nqQzSeGJ29r0zHhuflwKpGzY4TJxYy//+b/LulTfe8DFiRIC3387P19BTT/m55ZZqfD7o3z+9G5IA\njj22gy98If35k0n3eOt+u/NnoON0ZwceGOZHP4pcq5xuojl2bDuTJ7dirZ9Zs7xRkioTStbKnFeL\nCroudBTX9aIiGUln37uu7TK+MX5AVhKas2fU8vTg5HcLZmNf/+c/fTz9tJ9zzqnh008Tf5Nu2QJn\nn13LypV+Pvqo7906mzfDVVdV99hj8tFHDj/8YQ1VVS53391EfYEqOvT2eOvV43RvrVzp45RTannu\nud6dL62vhxkzWhkyJLMviauvbuHQQzv4wx8qeeCBLF1omSdK1oTQtJk0XnZlt19u2wjy2reuLkjZ\njiVL/Hzta4GUv85Fillo2kzu3Pe6bj1ebiDIpxddyTvf+RErVvgZMSLA/PlVtPehwsKwYR0Mfmx6\nwn3dDQSzViZk8OAOLr20lY8/9nH++TWEu3RKuS5Mm1bDmjU+LrqoheOP7/uvsjvvrOKOO6oS9pi0\nt8M559SwcaOPa69t4ZBDstNL1ls9HW9TfQa9Xc6L2tvh+ecrmDOnKq+nwqur4Ze/bKKuzuXOO6uK\nqkNApTtKWKZlB+KLCrY3DOCNA7/FFwf3y2GEifVUV60n4TC89pqP9et9jBmT/Nss4zbZsrl7ocX6\nPhST8iiV7ugs9rnHir/m6nNfvdrhyCP7MfKof/OnCQ8kLOj5xBN+Zsyo4ZNPfHzta+388Y877oJM\ntH1u8++E35+8TlpfC4im2l7CYZgwoZann67giitamPq9DdvX98w7ezHhkQl8aUiwx3pqmYqvv3bH\nz9YxsepP29/b/9SewoQpAxk7to27727O2R2kqdrEdeHtt33bT6n29jPIVfHXTZtgwYIqDjkkzNix\n6f0qWLPG4fe/r+Scc1rZddfE8/TULpMm1bJ0aWHKbrzyio/Pfz5MXV3vj/F9/W5QnTXZrli/gGOj\nFXzrW21p3enZ0QEHHxzE54O//70xaRX1UhrVIZuKdVvJhXx+7jfdVMWcOdUpC7xu2gSXX17D0Ud3\nMGlSW49xttcEmVdzKasn/ohrrkldyLW30tlePv3U4fjjA0xefwNXV/+UiuYdcTYSZOv5F+O/KntD\nD61e7fCXYbcwvfWn9KPzZ/fGiTOo/9nFfT79+f77DvPnVzNrVku3MhSp2uS++yqZObOa+fObc1rM\nt7d6U3ctVldtwYImvvOdxO+pp3ZZscLH6NFBhg5tZ+HCpr6G3yu5HkkimUyTNY0NWsKKcbxH14Up\nU2rZsMHhrrua07rb0+cDa/289FIFI0e2M3Bgz8uk2yaxauHxY80BOG1tVD3/LFRURMakKxHFuK3k\nQr4/90GDwuy+u8v48cnHuqythW9+s52DDw5HapH1EKevvY2jm5+Gigr2HD8kZ71I6WwvgQCc+u5P\nOfXvV3cacxOgijb6vfxMVttzz1/PZuQz13QaOxgin93At56hOtj3dS1aVMm8edW4Lt3uekzWJqtW\n+fj+92upq4Mrr2wp2DVzyey0U+Tavr/9rZIDDwzzxS8mP6OxZo3DtGk1fOYzYW66qaXHH8k9tcvA\ngS5vvOHnmWcqGDq0g333TX6sX7XKx4oVPg44wM3Kdt3bfT1bx4hMxwbVNWviKUuW+Fm50s+4ce0p\nT3/GGzWqPbp838+pOFs2E5g/N+k8gflzcbZmULBJPK8Qn/tee7lMndpKvzSvNnCc9OL8xpuz8W0r\n7PbpbNmMeWRO0nmy1Z75+uxiddfuvbeS9evTyxi2bYPJk2tpaXG47bYm9t7bu2ezpk5tpaLC5eab\nU1/PFbmG0uHii1t7XVdtxowWdtstzIYNqdvyhhuqOf30AK++2ve0JZ3tpWbeXOwr2zpdc1nI7wYl\na5K2Zcv8/OY3lTldR0UFHHhgB9OnZ9bLc+yxkdEMnnyy78laMYzqINlXLJ+74izcuqqrIwlNuqMa\nuC7MmFHD++/7OO+8VkaN8vYV7fGjGixc2POxdM2a5KMVpOuww8KsWNGY8jViddWGDm3nq1/t+w0i\n6Wwv/uZGfvXNv9ASdzVBIfc9JWuSllAocgfXrFnVWfll05MRIzpYvjz1TQVd9esHQ4d2sGqVnw8/\n7FsfeSlVepf0FcvnrjgLu65MetfWrXN49lk/hx/eweWX5+4awmyaOrWVysrIKcqeLFtW0edetZhk\nN8LExI9WkA3pbgdjD/+/Tu+vkPuekjVJSyAACxY009EBP/hBLZs25W5dvb0e4cwz27j22mZqa/t2\nmqHYR3WQ3imWz11xFnZdsd61jg545ZXkmcrAgS5PPx3innuaqMztSYms2XffxGMxxzvrrDb++tfU\nPWLZsGLFjl61dEcrSCXd7WDE6bt3upa0kPue7gYtYbm4w2/27Cpmz65m9Oh27rsvtwMp50I6beJs\n2cxuh3w+aXe3GwiycaUtmiKUqehu0MjnXv/Fz1PVmvvPfeVKHwcdFO7V/uOF7dNr+1G+26SlBTZu\ndNhzzx3fn9qHEutru1xwQQ0PPljJo4+Gspas9XZ7yeZ2lundoOpZk4xMn97K8OHtLFlSwe23F8lP\nxQyVWrVwSc9bH+3CDeFLk86Tjc99zRqHE04Icu65vRvypli2z3zGme82qa6mU6Im2REO023Uizlz\nmrnnnqasJWpQnCNJqHRHCctFOQafLzJW3gsv+Jk0qZ196v9DzcMPUbVsCf73/0nHoEFQnfpLyNmy\nefty/375n7j7D6KiX+7Ha0u3TdqGHA0VFVS8/lqnW7TdQJDQjEtLrs5auZfuaGyE006r5U8bjmXs\nt2Dgv17t9LlvI8ia/74M/1V9/9zvuquKF16o4NxzWznooN5dLB3bPisLtH1muh/lI85CtUnsWFa9\n7EnC9p20j4HFIv5YnckxPibdbWXbNhg1KsALf2lkknv/9vU5Bwzic4ekvpkjU73dXrK1nWVauiOn\np0GNMQ6wADgUaAYmW2vf7zJPAHgS+L619p3otEuBk4BKYIG19tcpVqXToAnkslvedSF4S/YKCjY6\nQVqmT6fjktx+yfRlVIdsVgv3mnI/hXPhhTU88EAlZ5/dyvXXt2z/3Ou2beL1j3fl2F9MYvDIAPff\n37fineEwHHlkkE8/dVi1alvaJTt6Uqjt08v7UT7XlehY1lIZpHX6dJovLv4fdFkq/pr2tvL4kFv4\nr3/+rFtR41wWIi/USBKZngbN9Uim44Bqa+1QY8xRwNzoNACMMYcDdwB7xU07BhgSXSYIXJzjGKUX\ngrdECgN25YQat09PtHPFCgp2ez23keDNP6axKvFymYr9BunrNXVuXT3NE0/f/rilBW6+oYqNGx1u\nvrk47u6S1EaNauejjxyuuirymcY+97qGOvb+ZCsHvR4ZGmfFCh+HHdb70gEvvujnX//yMX58W58T\ntfg4vS6fceZrXT0dy6rbGqn+2Y/x+bJzLCuUnt5fqmN8X9Z35j/zt76Y3m4v+d73cn3N2jDgCQBr\n7UvAEV2eryKSvL0dN200sMoYsxB4DHg8xzFKhnpbGDBfBQUfeqiCww4L8sYb2d+8q6rgr3+t4He/\nq8RaXfJZKsaMiYy5WV3d/TnH2VEyIJ3aWsk88EDkOs/x49tSzCleVuqFs/P9/kq9PbMh19829cDm\nuMftxpjt67TWvmit/RCI7//YHTgc+A5wLvD7HMcoGUq3MOBPj/gLY8fWZrxcXwsK1tbCRx/5ejWa\nwcaNDtu29fx85Iu7Bdd1mDs3+9dRSOEk64U9+ugO5s5t5uabU49Vm8zgwR2ceGIbgwd7uziqJFcs\nhYl7K9/vr9TbMxtyfRp0C1AX99hnrU11DmEj8Ja1th14xxjTbIzZ3Vr7abKFGhrqkj1dtnLSLtvS\nK7LW311PZWXFjhjSXK5u2ybq+hD3f/0XnHsuPPVUNTff3L2rJFmbzJoFCxfCs8/CF76QeJ7vfhfm\nzYOFCyv5yU8q+eIXex2qp2gfSizWLtOmAfTtwvGLLor8i1yOW9zKenvJ07GsYLL8/lJuK6XenlmQ\n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\nfp0YB1wAAAAASUVORK5CYII=\n",
      "text/plain": [
       "<matplotlib.figure.Figure at 0x11f89dfd0>"
      ]
     },
     "metadata": {},
     "output_type": "display_data"
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "## Retrain with new K Value\n",
    "\n",
    "**Retrain your model with the best K value (up to you to decide what you want) and re-do the classification report and the confusion matrix.**"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 21,
   "metadata": {
    "collapsed": false
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "WITH K=30\n",
      "\n",
      "\n",
      "[[127  25]\n",
      " [ 23 125]]\n",
      "\n",
      "\n",
      "             precision    recall  f1-score   support\n",
      "\n",
      "          0       0.85      0.84      0.84       152\n",
      "          1       0.83      0.84      0.84       148\n",
      "\n",
      "avg / total       0.84      0.84      0.84       300\n",
      "\n"
     ]
    }
   ],
   "source": []
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Great Job!"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.5.1"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 0
}