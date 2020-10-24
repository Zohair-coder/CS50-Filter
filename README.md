# Filter

Add filters to your images using this command line program!
Filter takes BMP images as input and applies a filter to them.

## Usage

```
./filter [FILTER] inputfile.bmp outputfile.bmp
```

The FILTER option can be substituted by one of the following:
* -g: Grayscale
* -s: Sepia
* -r: Reflection
* -b: Blur

## Example

```
./filter -g images/courtyard.bmp out.bmp
```
### Input Image:

![input-image](https://i.imgur.com/MEN23pg.png)

### Output Image:

![output-image](https://i.imgur.com/EucEBDU.png)


For more information, go to [CS50 pset4](https://cs50.harvard.edu/x/2020/psets/4/filter/less/)