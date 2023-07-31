```
(base) ➜  Beercraft git:(main) git tag -a 0.1-alpha -m "0.1-alpha update"
(base) ➜  Beercraft git:(main) git push origin main --tags 
```



3、当小伙伴从GitHub上将项目克隆下来之后，可以通过`git tag`命令来查看当前有哪些tag，如下：

```
复制代码git tag
```

4、比如我想退回到V20210310这个版本去，此时通过`git show V20210310`命令来查看对应的版本号，如下：

```sql
复制代码git show V20210310
```

commit后面的就是对应的提交版本号，然后通过`git reset --hard b1014a2a4fef206bba50d970b7133c2de313b1b4`命令即可回到只有权限管理模块的时代。如下：

```css
css
复制代码git reset --hard b1014a2a4fef206bba50d970b7133c2de313b1b4
```

GIT删除本地tag和远程tag

以tag V20210310，这个tag已经同步到远程，但是现在发现了一个问题，需要撤回该tag，git命令如下：

删除本地tag：

```
复制代码git tag -d V20210310
```

删除远端tag:（本地删除后，再删除远端tag(推送一个空的tag到远端tag，用空值覆盖原值)：）

```ruby
ruby
复制代码git push origin :refs/tags/V20210310
```

也可以使用 --delete 参数：

```perl
perl
复制代码git push origin --delete tag V20210310
```

