<!-- 单位报告 -->
<template>
  <div>
    <el-container>
      <el-aside width="200px">
        <PeoplleList title="报告查询"></PeoplleList>
      </el-aside>
      <el-main>
        <h2>报告信息</h2>
        <div>
          <el-form :inline="true">
            <el-form-item label="报告编号">
              <el-input placeholder="请输入" clearable class="input" />
            </el-form-item>
            <el-form-item label="体检类型">
              <el-input placeholder="请输入" clearable class="input" />
            </el-form-item>
            <el-form-item label="体检单位">
              <el-input placeholder="请输入" clearable class="input" />
            </el-form-item>
            <el-form-item label="委托单位">
              <el-input placeholder="请输入" clearable class="input" />
            </el-form-item>
            <el-form-item label="报告日期">
              <el-input placeholder="请输入" clearable class="input" />
            </el-form-item>
            <el-form-item label="体检人数">
              <el-input placeholder="请输入" clearable class="input" />
            </el-form-item>
            <el-form-item label="体检项目">
              <el-input placeholder="请输入" clearable type="textarea" />
            </el-form-item>
            <el-form-item label="评论依据">
              <el-input placeholder="请输入" clearable type="textarea" />
            </el-form-item>
            <el-form-item label="体检结论与处理意见">
              <el-input placeholder="请输入" clearable type="textarea" />
            </el-form-item>
          </el-form>
        </div>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import PeoplleList from '@/components/peoplelist/PeopleList.vue'
</script>

<style lang="scss" scoped>
.input {
  --el-input-width: 150px;
}
</style>
