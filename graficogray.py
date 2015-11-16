import plotly.plotly as py
from plotly.graph_objs import *
from math import sqrt
def dev(media, lista):
   sum = 0
   i =0
   for j in lista:
     sum  += (j-media)**2
   i = sum/len(lista)
   return sqrt(i)


# gray 1 = 11.153.408
# gray 2 = 6.971.392
# gray 3 = 6.533.120
# gray 4 = 11.618.304
sequencial = Scatter(  
    x = [6533120,6971392, 11153408, 11618304],
    y = [3.086, 3.267, 4.593, 5.469],
    name ="Sequencial",
    error_y=ErrorY(
        symmetric=False,
        type='data',
        color = 'rgb(255, 0, 0)',
        array = [0.328, 0.376, 1.236, 0.604],
        arrayminus = [0.526, 0.535, 0.223, 1.916],
        visible=True
    ),
    visible=True,
    xaxis='x',
    yaxis='y'
)

'''
otimizado = Scatter( #sequencial com -O3
    x=[250, 500, 1000,1500,2000,3000,4000],# cada um  eh a ordem de uma matriz
    y=[0.117,0.823,6.855,22.650,54.352,179.004,324.299], # cada um eh a media dos tempos de execucao da matriz;;;
    name='Otimizado',
    error_y=ErrorY(
        symmetric=False,
        type='data',
        color='rgb(255, 0, 0)',
        array=[0.033, 0.047, 0.04,0.106,4.06,0.615,0.46], # num do maior tempo de execucao menos a media
        arrayminus=[0.015,0.024,0.041,0.103,1.151,0.736,0.485], # media menos o menor tempo de execucao
        visible=True
    ),
    visible=True,
    marker=Marker(
        color='rgb(0, 0, 0)')
)

thread3 = Scatter(  #com 3 thread s
    x=[250,500,1000,1500,2000,3000,4000],
    y=[0.107,0.644,5.178,17.079,39.038,127.821,229.525],
    name ="3 threads",
    error_y=ErrorY(
        symmetric=False,
        type='data',
        color = 'rgb(255, 0, 0)',
        array=[0.021,0.002,0.06,0.157,0.409,1.103,3.058],
        arrayminus=[0.003,0.018,0.094,0.114,0.135,0.437,0.856],
        visible=True
    ),
    visible=True,
    xaxis='x',
    yaxis='y'
)

thread4 = Scatter( # com 4 threads
    x=[250,500,1000,1500,2000,3000,4000],
    y=[0.131,0.717,4.961,14.538,31.486,101.212,180.395],
    name="4 threads",
    error_y=ErrorY(
        symmetric=False,
        type='data',
        color = 'rgb(255,0,0)',
        array=[0.033,0.041,0.278,0.296,1.110,1.805,7.617],
        arrayminus=[0.006,0.028,0.133,0.239,0.293,1.205,2.445],
        visible=True
        ),
    visible=True,
    xaxis='x',
    yaxis='y'
)
'''
layout = Layout(
    showlegend=True,
    autosize=True,
    width=500,
    height=500,
    xaxis=XAxis(
        title='Pixels',
       
        type='linear',
        autorange=True
    ),
    yaxis=YAxis(
        title='Tempo',
        
        type='linear',
        autorange=True
    ),
    margin=Margin(
        l=65,
        r=50,
        b=65,
        t=65
    ),
    hovermode='x',
    dragmode='zoom'
)

data = Data([sequencial])
fig = Figure(data=data, layout=layout)
#py.image.save_as({'data':data,'layout':layout},'img\\a.png')
url = py.plot(fig)