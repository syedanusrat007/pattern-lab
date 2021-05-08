he = imread('18.png');
 figure(1);
imshow(he), title('Input image');

lab_he = rgb2lab(he);
ab = lab_he(:,:,2:3);
nrows = size(ab,1);
ncols = size(ab,2);
ab = reshape(ab,nrows*ncols,2);

nColors = 3;

[cluster_idx, cluster_center] = kmeans(ab,nColors,'distance','cityblock', ...
                                      'Replicates',3);
pixel_labels = reshape(cluster_idx,nrows,ncols);
 figure(2);
imshow(pixel_labels,[]), title('image labeled by cluster index');
segmented_images = cell(1,3);
rgb_label = repmat(pixel_labels,[1 1 3]);

for i=1:3
    color = he;
    color(rgb_label ~= 3) = 0;
    segmented_images{1} = color;
end
 figure(3);
imshow(segmented_images{1}), title('objects in cluster');
figure(4);
imshow(segmented_images{2}), title('objects in cluster');
figure(3);
imshow(segmented_images{3}), title('objects in cluster');